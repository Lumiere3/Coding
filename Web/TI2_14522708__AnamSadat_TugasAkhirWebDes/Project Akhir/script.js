document.addEventListener('DOMContentLoaded', function () {
    var searchInput = document.getElementById('searchInput');
    var cardContainer = document.getElementById('cardContainer');

    cardContainer.addEventListener('mouseover', function (event) {
        var targetCard = event.target.closest('.card');

        if (targetCard) {
            targetCard.classList.add('shadow-lg');
            targetCard.style.cursor = 'pointer';

            const link = targetCard.getAttribute('data-link');

            targetCard.addEventListener('click', function handleClick() {
                window.open(link);
                targetCard.removeEventListener('click', handleClick);
            });
        }
    });

    cardContainer.addEventListener('mouseout', function (event) {
        var targetCard = event.target.closest('.card');

        if (targetCard) {
            targetCard.classList.remove('shadow-lg');
        }
    });
});