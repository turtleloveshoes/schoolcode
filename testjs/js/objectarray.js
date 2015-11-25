function clearList(){
	//reset list
	list=document.getElementById('resultlist');
		list.innerHTML="";
		list.innerText="";
	};
$(document).ready(function(){
	//this part keeps the default text dynamic
	var default_search="Enter the keyword..."; 
	
	$('input[type="text"]').attr('value', default_search).focus(function(){
			if($(this).val() == default_search){
					$(this).attr('value', '');
					$(this).addClass('highlight');
				}		
	}).blur(function(){
		if($(this).val() == ''){
				$(this).attr('value', default_search);
				$(this).removeClass('highlight');
			}
	});
	
	$('#word').keyup(function(){
			search_name = $(this).val();
		
			$('#SearchBox p').removeClass('wordhighlight');
		
		while(jQuery.trim(search_name) != '' || search_name == defualt_search){
		/*highlight it*/
			i=0;
			if(jQuery.trim(search_name) != '' || search_name == defualt_search){
				var aTag = document.createElement('a');
				aTag.setAttribute('name', i);
				aTag.setAttribute('id', "results");
				aTag.innerHTML = "";
				var aHref = document.createElement('a');
				aHref.setAttribute('href', i);
				aHref.setAttribute('id', "results");
				aHref.setAttribute('target', "page");
				aHref.innerHTML = "Link";
				i++;
				$("#SearchBox p:contains('" + search_name +"')").addClass('highlight').append(aTag);
				$("#SearchBox p:contains('" + search_name +"')").attr('id', "FOUND").clone().appendTo('#list').removeClass('highlight').append(aHref);
				
				var len=$("#SearchBox p:contains('" + search_name +"')").length;
					//alert(len);
				
			break;
			}
	}
		
			//alert("uh you are in the link list loop");
			 $("#results").setAttribute('name', "").setAttribute('href', '1').innerHTML("Link");
			
	//works
		/*for(j=0; j<allPar.length; j++){
						var divd=document.getElementById('FOUND');
						var aTag = document.createElement('a');
						aTag.setAttribute('href', j);
						aTag.innerHTML = "FOUND";
						divd.appendChild(aTag);
						alert(j +"this is the next FOUND Link");
				}


	
	}*/
				});
$('#word').keydown(function(){
	
		search_name = $(this).val();
});
});