var name = $('#name').val();
alert(name);

var text = $('#text').text();
alert(text);

$('#click_me').click(function() {
	alert('hello');
	
	});

$('p:last').text('HEllo this is jquery dynamic text with .text ');
$('p').text('HEllo this is jquery dynamic text with .text ');
//be careful this 'p' will also apply to p with ids