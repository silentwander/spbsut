// Image slider functionality
function prevImage(button) {
    const slider = button.parentElement.previousElementSibling;
    const images = slider.getElementsByTagName('img');
    let current = 0;
    for(let i = 0; i < images.length; i++) {
        if(images[i].style.display !== 'none') {
            current = i;
            break;
        }
    }
    images[current].style.display = 'none';
    images[(current - 1 + images.length) % images.length].style.display = 'block';
}

function nextImage(button) {
    const slider = button.parentElement.previousElementSibling;
    const images = slider.getElementsByTagName('img');
    let current = 0;
    for(let i = 0; i < images.length; i++) {
        if(images[i].style.display !== 'none') {
            current = i;
            break;
        }
    }
    images[current].style.display = 'none';
    images[(current + 1) % images.length].style.display = 'block';
}

// Tab switching functionality
function showContent(contentId) {
    document.querySelectorAll('.tab-content').forEach(content => {
        content.style.display = 'none';
        content.classList.remove('active');
    });
    
    document.getElementById(contentId).style.display = 'block';
    document.getElementById(contentId).classList.add('active');
    
    document.querySelectorAll('.tab-btn').forEach(btn => {
        btn.classList.remove('active');
    });
    document.querySelector('[onclick="showContent(\'' + contentId + '\')"]').classList.add('active');
}
