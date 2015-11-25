
$(window).load(function(){
		
		//good for after all images are loaded
		//waits for all content to load- not each individually
		alert('Loaded');
		
		
		});

$(window).unload(function() {
// loaded when the viewer navigates away from the page	
	
	var c = confirm('are you sure you want to leave? ');
	if(c){
		return true; 
		}
	else{
		return false;
		}
	});
	
	