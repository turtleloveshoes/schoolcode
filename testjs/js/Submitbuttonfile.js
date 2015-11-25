
$(document).ready(function(){
	
	//here
	//this is the id way
	//$('#file').change(function(){
		//value= $(this).attr('value');
		//alert(value);
		///$('#submit').removeAttr('disabled');
		//});	
	//this is the global way for all input types with file 
	$('input[type="file"]').change(function(){
		$(this).next().removeAttr('disabled');
		}).next().attr('disabled', 'disabled');
		//the first remove attr removes the ability to use the upload button 
		//the second adds the disabled attr everytime a file is submited after it is selected
});



