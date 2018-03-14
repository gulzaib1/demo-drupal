// SCROLL TOP
jQuery(document).ready(function(){
	jQuery('#return-to-top').click(function() {      // When arrow is clicked
		jQuery('body,html').animate({
			scrollTop : 0                       // Scroll to top of body
		}, 1000);
	});
});

