$(document).ready(function() {
	alert('Document is ready');
	$('iframe').load(function(){
		alert('All loaded iframes');
		
		});
	});
	
	$(window).load(function(){
		
		//good for after all images are loaded
		//waits for all content to load- not each individually
		alert('Loaded');
		
		
		});