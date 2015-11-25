$(document).ready(function(){
	var email_default = "Enter your email address...";
	var name_default = "Enter input...";
	
	$('input[type="email"]').attr('value', email_default);
	
	
	$('input[type="text"]').attr('value', name_default).focus(function(){
		if($(this).val() == email_default){
			$(this).attr('value', '');
			}
	}).blur(function(){
		if ($(this).val() == ''){
				$(this).attr('value', email_default);	
			}
	});
		
		
	
	$('a[href="http://www.google.com"]');
	
	
});