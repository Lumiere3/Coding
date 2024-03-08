document.addEventListener("DOMContentLoaded", function () {
    const navItems = document.querySelectorAll('.nav-item');

    window.addEventListener("scroll", function () {
        let currentScroll = window.scrollY;

        navItems.forEach(function (navItem) {
            const sectionId = navItem.getAttribute('data-target');
            const section = document.getElementById(sectionId);

            if (section.offsetTop <= currentScroll && section.offsetTop + section.offsetHeight > currentScroll) {
                navItem.classList.add('active');
            } else {
                navItem.classList.remove('active');
            }
        });
    });
});