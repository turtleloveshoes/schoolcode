$(document).ready(function(){
	
	//This is the functionality 
	function change_size(element, size){
		var current = parseInt(element.css('font-size'));
		//this parses the value of the 16px string to 16- allows to edit values
		if(size =='smaller'){
			var new_size = current-2;
			}
		else if (size == 'bigger'){
			var new_size = current+2;
			}
		element.css('font-size', new_size + 'px');
		};
	//These are the event handlres
	$('#smaller').click(function(){
		change_size($('p'), 'smaller'); 
		});
	$('#bigger').click(function(){
		change_size($('p'), 'bigger');
		
		});	
	});