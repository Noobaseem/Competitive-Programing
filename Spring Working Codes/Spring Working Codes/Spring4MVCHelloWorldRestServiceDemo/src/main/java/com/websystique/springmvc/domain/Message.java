package com.websystique.springmvc.domain;

import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Service;

@Service
@Scope(value = "prototype")
public class Message {

	String name;
	String text;
	
	public Message() {
		System.out.println("Message bean instantiated");
	}
	
	public Message(String name, String text) {
		this.name = name;
		this.text = text;
	}

	public String getName() {
		return name;
	}

	public String getText() {
		return text;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setText(String text) {
		this.text = text;
	}

}
