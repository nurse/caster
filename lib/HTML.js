/*


	Default HTML parser for AjaxChatClient


Copyright (c)2005,2006,2007 Nerry Kitazato, All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer. 
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/
new HTML;

function HTML(){

	HTML.parse=function(src, purl0){
		var out = "";
		var regexp = app.allow_tag_list;
		var list_empty = "^(meta|link|hr|br|img|input)$";
		var	tags=[];
		var a=[];
		var a_nest=0;
		if(src.match(/[\r\n]|<br \/>/)) src = ("\n" + src + "\n").replace(/\r\n|[\r\n]/g,"<br />"); 
		src = src.replace(/\t/g,"        "); 
		src = src.replace(/\s+/g," ");
		while(a=src.match(/^([^<]*)<(.*)$/)){
			var s=encodeEntity(decodeEntity(a[1]));
			if(HTML.auto_link){
				if(!a_nest){
					s=s.replace(app.regexp_autolink,function(a,v1,v2){
						if(v2.length<=64) {
							return v1+"<a class=\"autolink\" onclick="+escapeAttribute("return nav(this.href)")+" href="+escapeAttribute(decodeEntity(v2))+">"+v2+"</a>";
						} else {
							return v1+"<a class=\"autolink\" onclick="+escapeAttribute("return nav(this.href)")+" href="+escapeAttribute(decodeEntity(v2))+" title=\""+v2+"\">"+v2.substr(0, 61)+"...</a>";
						}
					}
					);
				}
			}
			out+=s;
			src = a[2];
			if(a=src.match(/^([A-Za-z][\w]*)([^>]*)>(.*)$/)){
				var	tn	= a[1];
				var	ta	= a[2];
				var	tr	= a[3];

				//if(tn.match(/^br$/i)) ta = " /";

				if(tn.match(list_empty) && !ta.match(/\/$/)){
					ta += " /";
				}

				var	tat	= ta.match(/\/$/) ? 1:0;
				if(!tat) tags.push(tn)
				if(tn.match(regexp)){
					var bad_tag=0;
					var	ta2 = {};
					var	ta3 = ta.replace(/\s+$/,"");
					while(a=ta3.match(/^\s*([A-Z][\w\:\-]*\w*)\s*\=\s*([^\"\'\s]\S*|\"[^\"]*\"|\'[^\']*\')(\s*.*)$/i)){
						ta3 = a[3];
						var	an = a[1];
						switch(a[2].substr(0,1)){
						case '"':
						case "'":
							a[2]=a[2].substr(1,a[2].length-2);
						}
						if(!an.match(/^(on.*|style|id|name|class|clear|target)$/i)){
							ta2[a[1].toLowerCase()]=decodeEntity(a[2].replace(/\"/g,"&#34;"));
						}
					}
					if(tn.match(/^a$/i)){
						if(a_nest){
							bad_tag=1;
						}else{
							if(ta2["href"]){
								var href=ta2["href"].replace(/\"/g,'');
								if(href.indexOf(purl0)==0){
									href=href.substr(purl0.length);
								}
								if(!href.match(/^(\w+)\:/)){
									delete ta2["href"];
								}else{
									ta2["title"]	= "link: "+href;
									ta2["onclick"]	= "return nav(\""+href+"\")";
									ta2["href"]		= href;
								}
							}else{
								bad_tag=1;
								ta2["onclick"]	= "return false;";
							}
						}
						a_nest++;
					}
					if(tat && !tn.match(list_empty)){
						out += "<strong class=\"badtags\">&lt;"+tn+ta+"&gt;</strong>";
					}else{
						if(bad_tag || ta3.replace(/\s*\/$/,"").length){
							out += "<strong class=\"badtags\">&lt;"+tn+ta+"&gt;</strong>";
						}
						out += "<"+tn;
						for(var key in ta2){
							out += " "+key+"="+escapeAttribute(ta2[key]);
						}
						if(tat){
							out += " />";
						}else{
							out += ">";
						}
					}
				}else{
					out += "<strong class=\"badtags\">&lt;"+tn+ta+"&gt;</strong>";
				}
				src = tr;
			}else if(a=src.match(/^\/(\w+)>(.*)$/)){
				var	tn=a[1];
				var	tr=a[2];
				var	tcn = tags.pop();
				if(tcn == tn){
					if(tn.match(/^a$/i)){
						a_nest--;
					}
					if(tn.match(regexp)){
						out += "</"+tn+">";
					}else{
						out += "<del class=\"badtags\">&lt;/"+tn+"&gt;</del>";
					}
				}else{
					out += "<del class=\"extratags\">&lt;/"+tn+"&gt;</del>";
					if(tcn) out += "<ins class=\"notags\">&lt;/"+tcn+"&gt;</ins></"+tcn+">";
				}
				src = tr;
			}else{
				out += "&lt;";
			}
		}
		if(HTML.auto_link){
			out += encodeEntity(decodeEntity(src)).replace(app.regexp_autolink,function(a,v1,v2){
				if(v2.length<=64) {
					return v1+"<a class=\"autolink\" onclick="+escapeAttribute("return nav(this.href)")+" href="+escapeAttribute(decodeEntity(v2))+">"+v2+"</a>";
				} else {
					return v1+"<a class=\"autolink\" onclick="+escapeAttribute("return nav(this.href)")+" href="+escapeAttribute(decodeEntity(v2))+" title=\"link: "+v2+"\">"+v2.substr(0, 61)+"...</a>";
				}
			}
			);
		}else{
			out+=encodeEntity(decodeEntity(src));
		}

		while(tags.length){
			var	tn = tags.pop();
			out += "<ins class=\"notags\">&lt;/"+tn+"&gt;</ins></"+tn+">";
		}
		//return encodeEntity(out);
		return out;
	}
}
