$(':text').focusin(function(){
		
	$(this).css('background-color','yellow');
	
	});
$(':text').blur(function(){
		
	$(this).css('background-color','white');
	
	});
	
$(':input').focusin(function(){
		
	$(this).css('background-color','yellow');
	
	});
$(':input').blur(function(){
		
	$(this).css('background-color','white');
	
	});
	
$(':button').click(function(){
	$('p').css('background-color', '#000').css('color', 'white');
	
	});