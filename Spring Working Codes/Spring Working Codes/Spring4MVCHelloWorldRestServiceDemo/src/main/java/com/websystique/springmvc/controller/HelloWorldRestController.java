package com.websystique.springmvc.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.websystique.springmvc.domain.Message;

@RestController
public class HelloWorldRestController {

	@Autowired
	private Message message;
	
	@Autowired
	private Message message1;
	
	@RequestMapping("/hello")
	public Message messageAnonymous() {

		message.setText("hi");
		return message;
	}
	
	@RequestMapping("/hello/{player}")
	public Message message(@PathVariable String player) {

		message1.setName(player);
		message1.setText("hello");
		return message1;
	}

}
