$(document).ready(function(){
	$('#message').fadeIn('3000');
	

//the show hide pannel
   $("div#par1").hide();
   $("button#hide").hide();
	$("button#show").click(function(){
			$("div#par1").slideDown('medium');
			$("button#show").hide();
			$("button#hide").show();
		});
	$("button#hide").click(function(){
			$("div#par1").hide();
			$("button#show").show();
			$("button#hide").hide();
		});
	$("img").mouseover(function(){
			var src = $(this).attr("src");
			$("div#intro#display").attr("src").replace("?:/[^/#?]+)+\.(?:jpg|gif|png)$", src);
			
		});

	
	var name_default = "Enter your name";
	var email_default = "Enter your email address...";
	var feed_default = "Enter your comment here";
	
	$('input[type="email"]').attr('value', email_default);
	$('input[type="test"]').attr('value', feed_default);

	});