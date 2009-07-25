//
//	Maple Ajax Core Libraries
//
//	Copyright (C)2005,2006 WAHAH.jp, ALL RIGHTS RESERVED.
//
//	encoded in UTF-8 文字コードあいうえお
//

new Maple;

function Maple(){

	getXMLHttpRequest=function(){
		if(window.ActiveXObject){
			try{
				return new ActiveXObject("MSXML2.XMLHTTP");
			}catch(e){
				return new ActiveXObject("Microsoft.XMLHTTP");
			}
		}else if(window.XMLHttpRequest) {
			return new XMLHttpRequest();
		}else{
			throw new Error("Sorry, DOM not available");
		}
	};


	Maple.Post=function(url,query,delegate,param){
		return send_request(true,url,query,delegate,param,true);
	}

	Maple.Get=function(url,query,delegate,param,cc){
		var q=url.match(/^([^\?]+)\?(.*)$/);
		if(q){
			url		= q[1];
			query	= q[2]+"&"+query;
		}
		return send_request(false,url,query,delegate,param,cc);
	}

	send_request=function(isPost,url,query,delegate,param,cc){
		var req = getXMLHttpRequest();
		var	ua = navigator.userAgent+" Maple/20060501 "+app.name;
		req.onreadystatechange = function(){
				if(req.readyState == 4){
					delegate(req,param);
				}
			};
		if(isPost){
			req.open("POST", url+"?NOCACHE"+parseInt(new Date().valueOf()), true);
			try{
				req.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
				req.setRequestHeader("User-Agent",ua);
			}catch(e){}
			req.send(query);
		}else{
			req.open("GET", url+"?"+query+(cc?"&NOCACHE"+parseInt(new Date().valueOf()):"") , true);
			try{
				req.setRequestHeader("User-Agent",ua);
			}catch(e){}
			req.send(null);
		}
		return req;
	}
}


function getInnerXML(domElement){
	if(!domElement) return "";
	var cn=domElement.childNodes;
	var a=[];
	for(var i=0;i<cn.length;i++){
		a.push(getOuterXML(cn.item(i)));
	}
	cn=null;
	return a.join("");
}

function getOuterXML(domElement){
	var nn = ""+domElement.nodeName;
	var s="";
	switch(nn){
	case "#text":
		return encodeEntity(domElement.nodeValue);
	case "#cdata-section":
		return "<![CDATA["+domElement.nodeValue+"]]>";
	case "#comment":
		return "<!--"+domElement.nodeValue+"-->";
	default:
		var atrs=domElement.attributes,atra=[];
		if(atrs&&atrs.length){
			for(var i=0;i<atrs.length;i++){
				if(!atrs.item(i).name.match(/^xml\w+/)){
					atra.push(atrs.item(i).name+"="+escapeAttribute(atrs.item(i).value));
				}
			}
		}
		s="<"+nn+" "+atra.join(" ");
		atrs=null;
		var cn=domElement.childNodes;
		if(cn&&cn.length){
			s+=">";
			var coxa=[];
			for(var i=0;i<cn.length;i++){
				coxa.push(getOuterXML(cn.item(i)));
			}
			s+=coxa.join("")+"</"+nn+">";
			coxa=null;
		}else{
			s+="/>";
		}
		cn=null;
	}
	return s;
}

function getElementText(domElement){
	if(!domElement) return "";
	var s=domElement.nodeValue;
	if(s==null) s="";
	var cn=domElement.childNodes;
	for(var i=0;i<cn.length;i++){
		s+=getElementText(cn.item(i));
	}
	return s;
}

function getNamedChildElement(element,name){
	var r=null,cn=null;
	try{
		if(element){
			cn=element.childNodes;
			if(cn&&cn.length){
				for(var i=0;i<cn.length;i++){
					if(cn.item(i).nodeName==name){
						return cn.item(i);
					}
				}
			}
		}
	}finally{
		cn=null;
	}
	return r;
}

function getNamedChildElementArray(element,name){
	var a=[],cn=null;
	if(element){
		cn=element.childNodes;
		if(cn&&cn.length){
			for(var i=0;i<cn.length;i++){
				if(cn.item(i).nodeName==name){
					a.push(cn.item(i));
				}
			}
		}
	}
	cn=null;
	return a;
}

function escapeAttribute(s){
	return "\""+encodeEntity(s)+"\"";
}

function encodeEntity(s){
	return (""+s).replace(/&/g,"&amp;").replace(/\"/g,"&quot;").replace(/</g,"&lt;").replace(/>/g,"&gt;");
}

function decodeEntity(s){
	var	entity = {"lt":"&#x3C;","gt":"&#x3E;","amp":"&#x26;","apos":"&#x27;","quot":"&#x22;","nbsp":"&#160;","copy":"&#169;","hearts":"&#x2665;"};
	s=s.replace(/\&(\w+);/g,function(a,v){
			var t=entity[v]
			return t?t:"&"+v+";";
		}).replace(/\&\#(\d+);/g,function(a,v){
			return String.fromCharCode(v);
		}).replace(/\&\#x([0-9A-Fa-f]+);/g,function(a,v){
			return String.fromCharCode(eval("0x"+v));
		});
	return s;
}

function encodeQuery(s){
	return (""+s).replace(/[\0-\x7F]/g,function(a0){
			if(a0==" ")return "+";else if(a0.match(/\w/))return a0;else return escape2H(a0.charCodeAt(0));
		}).replace(/[^\0-\x7F]+/g,function(a0){
			return encodeURIComponent(a0);
		});
}

function escape2H(c){
	var	hex_tab = "0123456789ABCDEF";
	return "%"+hex_tab.charAt(c>>4&0xF)+hex_tab.charAt(c&0xF);
}

function date_to_date(s){
	var string=""+s;
	var	regexp = new RegExp("(\\d{4})-(\\d{2})-(\\d{2})T(\\d{2}):(\\d{2}):(\\d{2})(?:Z|([-+])(\\d{2})(?::(\\d{2})))?");
	var matched = string.match(regexp);
	if(matched){
		if(!matched[7] || !matched[8]){
		}else if('+' == matched[7]){
			matched[4] -= matched[8];
			if(matched[9])matched[5] -= matched[9];
		}else{
			matched[4] += matched[8];
			if(matched[9])matched[5] += matched[9];
		}
		return new Date(Date.UTC( matched[1], matched[2]-1, matched[3], matched[4], matched[5], matched[6] ));
	}else{
		return null;
	}
}

