#!/usr/bin/python3
import platform,re, os, shutil, signal, sys,  threading, time, urllib, subprocess, hashlib, time,psutil, cgi,datetime,cgitb,pprint, json


# Initialize Language Constants
php_prefix  = "<?php ini_set('log_errors',1); ini_set('error_log','[folder]error.txt'); ?>";
ioeredirect = " 0<[folder]input.txt 1>[folder]output.txt 2>[folder]error.txt"
folder      = "/home/[users]/data/[hash]/"
actualfolder= "data/[hash]/"
ssh	    = "sshpass  -p [available] ssh -o StrictHostKeyChecking=false localhost -l [available] "
base_path   = "/home/"


# Addition of new Language requires change below 
# NOTE : You may need to add few lines in 'create' function too on addtion of new language.
langarr = {
"AWK": {"extension": "awk", "system":"find /usr/bin/ -name awk", "execute":"awk -f [folder][exename].awk[inputfile]"},
"Bash": {"extension": "sh", "system":"find /bin/ -name bash", "execute":"bash [folder][exename].sh[inputfile]"},
"C" : {"extension":"c", "system":"find /usr/bin/ -name cc", "compile":"gcc [folder][codefilename].c -O2 -fomit-frame-pointer -o [folder][codefilename] -lm"+ioeredirect, "execute":"[folder][exename][inputfile]"},
"C++": {"extension": "cpp", "system": "find /usr/bin/ -name g++", "compile": "g++ [folder][codefilename].cpp -O2 -fomit-frame-pointer -o [folder][codefilename]"+ioeredirect, "execute": "[folder][exename][inputfile]"},
"C#" : {"extension": "cs", "system":"find /usr/bin/ -name gmcs", "compile":"gmcs [folder][codefilename].cs -out:[folder][codefilename].exe"+ioeredirect, "execute":"mono [folder][exename].exe[inputfile]"},
"Java" : {"extension" : "java", "system":"find /usr/bin/ -name javac", "compile":"javac -g:none -Xlint -d [folder] [folder][codefilename].java"+ioeredirect, "execute":"java -client -classpath [folder] [exename][inputfile]"},
"JavaScript": {"extension":"js", "system": "find /usr/bin/ -name rhino", "execute":"rhino -f [folder][exename].js[inputfile]"},
"Pascal": {"extension":"pas", "system":"find /usr/bin/ -name fpc", "compile":"fpc [folder][codefilename].pas -O2 -o[folder][codefilename]"+ioeredirect, "execute":"[folder][exename][inputfile]"},
"Perl": {"extension":"pl", "system":"find /usr/bin/ -name perl", "execute":"perl [folder][exename].pl[inputfile]"},
"PHP": {"extension":"php", "system":"find /usr/bin/ -name php", "execute":"php -f [folder][exename].php[inputfile]"},
"Python": {"extension":"py", "system":"find /usr/bin/ -name python2", "execute":"python2 [folder][exename].py[inputfile]"},
"Python3": {"extension":"py", "system":"find /usr/bin/ -name python3", "execute":"python3 [folder][exename].py[inputfile]"},
"Ruby": {"extension":"rb", "system":"find /usr/bin/ -name ruby", "execute":"ruby [folder][exename].rb[inputfile]"}
}

# Define useful variables

running = 0
mypid = int(os.getpid())
timediff = 0
languages = []
finaldescription = "none"
finalresult = "none"
finaltimetaken= 0.0
finalmemory = 0 

# File Read/Write Functions
def file_read(filename):
	if not os.path.exists(filename): return "";
	f = open(filename,"r",encoding='utf-8'); d = f.read(); f.close(); return d.replace("\r","")
def file_write(filename,data):
	f = open(filename,"w"); f.write(data.replace("\r","")); f.close();

# Systems Check
def system(path):
	global languages
	if not os.path.isdir(path): #os.makedirs(path)
		os.system(ssh+" mkdir data")
		os.system(ssh+" mkdir "+path)
	for lang in langarr:
		if(os.popen(langarr[lang]["system"]).read()!=""): languages.append(lang);

# Program Compilation
def create(codefilename,language):
	if(language not in ('C','C++','C#','Java','Pascal')): return
	#print("Compiling Code File ...")
	result = None
	compilecmd = langarr[language]["compile"]
	compilecmd = compilecmd.replace("[codefilename]", codefilename)
	compilecmd = compilecmd.replace("[folder]", actualfolder)
	#print(ssh+"'"+compilecmd+"'")
	if language=="Java":
		os.system(ssh+"'"+compilecmd+"'")
		if ((not os.path.exists(folder + codefilename+".class")) and (not os.path.exists(folder + "main/"+codefilename+".class"))):
			result="CE"
	elif language=="C#":
		os.system(ssh+"'"+compilecmd+"'")
		if not os.path.exists(folder +codefilename+".exe"): 
			result="CE"
	else:
		os.system(ssh+"'"+compilecmd+"'")
		if not os.path.exists(folder +codefilename):
			result="CE"

	return result

# Program Execution
def execute(exename,language, timelimit):
	global running, timediff
	inputfile = " < " + actualfolder + "input.txt 1>" + actualfolder + "output.txt 2>" + actualfolder + "error.txt"
	if language == "Java" and not(os.path.exists(folder+exename+".class")): 
			exename = actualfolder + "main/" + exename
	cmd = ssh+"'"+langarr[language]["execute"]+"'; exit;"
			 
	cmd = cmd.replace("[exename]", exename)
	cmd = cmd.replace("[inputfile]", inputfile)
	cmd = cmd.replace("[folder]", actualfolder)
	
	if(os.path.exists(folder + "input.txt")): os.system(ssh+"chmod 777 " + actualfolder + "input.txt")
	if(os.path.exists(folder + "error.txt")): os.system(ssh+"chmod 777 " + actualfolder + "error.txt")
	if(os.path.exists(folder + "output.txt")): os.system(ssh+"chmod 777 " + actualfolder + "output.txt")
	starttime = time.time()

	t=[]
	proc = subprocess.Popen([cmd], shell=True, preexec_fn=os.setsid)
	p = psutil.Process(proc.pid)
	mem = p.get_memory_info()[0]
	t.append(mem)
	
	try:		
		proc.communicate(timeout=timelimit)
		t.append(proc.returncode)
	except subprocess.TimeoutExpired:
		t.append(124)
		#system command to kill process running thorugh logged in user in case of tle
		os.system(ssh+"'pkill -u `whoami`'")
	endtime = time.time()
	timediff = endtime - starttime
	return t

sys.stdout.flush();
def runjudge(run,finalresult,finaldescription,finaltimetaken,finalmemory):
	try:
		
		# Initialize Variables
		result = None; timetaken = 0; running = 0
		sys.stdout.flush();

		# Write Code & Input File
		if result==None:
			if run["language"]=="Java": codefilename = run["name"]
			else: codefilename = "code";
		
			os.system(ssh+"'echo \""+run["input"]+"\">>"+ actualfolder+"input.txt'")
			
			run["code"]=run["code"].replace("\r","")
			run["code"]=run["code"].replace('"','\\\"')
			run["code"]=run["code"].replace("\\n",'\\\\\\n')
			run["code"]=run["code"].replace("'",'\\\"')
			if run["language"]=="PHP":run["code"]=run["code"].replace("$",'\\$')

			extn=langarr[run['language']]['extension']
			#if(run["language"]=="PHP"): os.system(ssh+"'echo \""+php_prefix +"\">>"+ actualfolder+codefilename+"."+extn+"'")
			#pprint.pprint(run["code"])
			os.system(ssh+"'echo \""+run["code"] +"\">>"+ actualfolder+codefilename+"."+extn+"'")
			

		# Compile, if required
		if result==None:
			result = create(codefilename,run["language"]); # Compile
		sys.stdout.flush();
		# Increase Time Limit in case some languages
		if run["language"] in ('Java', 'Python', 'Python3', 'Ruby', 'PHP', 'C#', 'JavaScript'):
			if run["language"] in ("Java", "C#", "JavaScript"):
				run['timelimit'] *= 2;
			elif run["language"] in ("Python", "Ruby", "PHP", "Python3"):
				run['timelimit'] *= 3;

		# Run the program through a new thread, and kill it after some time
		if result==None:
			running = 0
			response = []
			response = execute(codefilename,run["language"], run['timelimit'])
			t=int(response[1])
			finalmemory=int(response[0])
			
			#while running==0: pass # Wait till process begins
			if t == 124:
				result = "TLE"
				timetaken = run["timelimit"]
				finaldescription="Time Limit Exceeded"
				os.system(ssh+"'echo \"Time Limit Exceeded - Process killed.\">>"+actualfolder+"error.txt'")
			elif t == 139:
				finaldescription="SIGSEGV"
				result="RE"
				os.system(ssh+"'echo \"SIGSEGV||Segmentation fault (core dumped)\n\">>"+actualfolder+"error.txt'")
				timetaken = timediff
			elif t == 136:
				os.system(ssh+"'echo \"SIGFPE||Floating point exception\n\">>"+actualfolder+"error.txt'")
				result="RE"
				finaldescription="SIGFPE"
				timetaken = timediff
			elif t == 134:
				os.system(ssh+"'echo \"SIGABRT||Aborted\n\">>"+actualfolder+"error.txt'")
				result="RE"
				finaldescription="SIGABRT"
				timetaken = timediff
			elif t != 0:
				finaldescription="NZEC"
				result="RE"
				os.system(ssh+"'echo \"NZEC||return code : "+str(t)+"\">>"+actualfolder+"error.txt'")
				timetaken = timediff
			else:
				timetaken = timediff
		sys.stdout.flush();
		# Compare the output
		output = ""
		if result==None:
			os.system(ssh+"'grep -P -v \"^\s*$\" "+actualfolder+"/output.txt > "+actualfolder+"/foo;mv "+actualfolder+"/foo "+actualfolder+"/output.txt'")
			output = file_read(folder + "output.txt")
			output = output.replace("\r","")
			correct = run["output"].replace("\r","")
			if run["output"] is None: run["output"] = ""
			
			if(output==correct): 
				result="AC"
			elif "S" in run["output"] and re.sub(" +"," ",re.sub("\n *","\n",re.sub(" *\n","\n",output)))==re.sub(" +"," ",re.sub("\n *","\n",re.sub(" *\n","\n",correct))): 
				result = "AC"
			elif(re.sub(r"\s","",output)==re.sub(r"\s","",correct)): 
				result = "AC" if "P" in run["output"] else "PE"
			else: result = "WA"
		
		finalresult=result
		
		# Write results to database
		error = file_read(folder + "error.txt")
		#print("Result (%s,%.3f) updated on Server.\n" % (result,timetaken))
		sys.stdout.flush();
		finaltimetaken='%.2f' %timetaken
		# Disconnect from Server
		sys.stdout.flush();
		result = {'success':'true','result':finalresult,'description':finaldescription,'time':finaltimetaken,'memory':finalmemory}
		print(json.dumps(result)) 
	except ZeroDivisionError as  e:
	    someerror="some error"

if __name__ == "__main__":
	print ("Content-Type: application/json\n")
	#cgitb.enable()
	
	#initializing variables
	run = {}
	form = cgi.FieldStorage()
	run["code"]  	 = form.getvalue('code')
	run["timelimit"] = float(form.getvalue('time'))
	run["memory"]    = float(form.getvalue('mem'))
	run["language"]  = form.getvalue('lang')
	run["input"]     = form.getvalue('input')
	run["name"]      = 'Main'
	run["output"]    = form.getvalue('output')
	#pprint.pprint(run["code"])
	
	flag      = 0;
	available ="sample"
	compilers = []
	fobj = open("users.list")
	for line in fobj:
		compilers.append(line.rstrip())
	fobj.close()
	while available=="sample":
	
		for com in compilers:
			#print(base_path + com +"/use.txt")
			if not os.path.exists(base_path + com +"/use.txt"):
				available=com
				flag=1

			if flag==1:
				break

	

	#pprint.pprint(available)
	hash        = hashlib.md5(((str)(time.time()) + "").encode('utf-8')).hexdigest()
	folder      = folder.replace("[hash]", hash)
	folder= folder.replace("[users]", available)
	actualfolder= actualfolder.replace("[hash]", hash)
	ioeredirect = ioeredirect.replace("[folder]", actualfolder)
	php_prefix  = php_prefix.replace("[folder]", actualfolder)
	ssh         = ssh.replace("[available]", available)


	os.system(ssh+" touch use.txt")

	system(actualfolder)

	
	
	runjudge(run,finalresult,finaldescription,finaltimetaken,finalmemory)
	os.system(ssh+"'rm -rf data/ use.txt'")
