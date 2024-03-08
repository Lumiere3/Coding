document.addEventListener('DOMContentLoaded', function () {
    var searchInput = document.getElementById('searchInput');
    var cardContainer = document.getElementById('cardContainer');
    var cardRow = document.getElementById('cardRow');
    var initialCards = Array.from(cardRow.children); // Salin daftar card awal
    var noResultMessage = document.createElement('div'); // Elemen untuk pesan no result
    noResultMessage.textContent = 'No result';
    noResultMessage.id = 'noResultMessage';

    // Tambahkan event listener untuk input pencarian
    searchInput.addEventListener('input', function () {
        var filter = searchInput.value.toLowerCase();
        var filteredCards = [];

        // Loop melalui setiap card awal
        for (var i = 0; i < initialCards.length; i++) {
            var cardTitle = initialCards[i].getElementsByClassName('card-title')[0].textContent.toLowerCase();

            // Tentukan apakah card harus ditampilkan atau disembunyikan berdasarkan judul
            if (cardTitle.includes(filter)) {
                filteredCards.push(initialCards[i].cloneNode(true)); // Duplikat card sebelum menambahkannya
            }
        }

        // Urutkan card berdasarkan judul sebelum menambahkannya kembali ke DOM
        filteredCards.sort(function (a, b) {
            var titleA = a.getElementsByClassName('card-title')[0].textContent.toLowerCase();
            var titleB = b.getElementsByClassName('card-title')[0].textContent.toLowerCase();
            return titleA.localeCompare(titleB);
        });

        // Hapus semua card dari DOM
        while (cardRow.firstChild) {
            cardRow.removeChild(cardRow.firstChild);
        }

        // Tampilkan pesan "No result" jika hasil pencarian kosong
        if (filteredCards.length === 0) {
            cardRow.appendChild(noResultMessage);
        } else {
            // Tambahkan kembali card yang telah difilter dan diurutkan ke DOM
            for (var j = 0; j < filteredCards.length; j++) {
                // Tambahkan class Bootstrap setelah pengurutan
                filteredCards[j].classList.add('col-lg-4', 'col-md-6', 'mt-5', 'col-6');
                cardRow.appendChild(filteredCards[j]);
            }
        }
    });

    // Inisialisasi cards saat halaman dimuat
    var cardElements = document.getElementsByClassName('card');
    var cards = Array.from(cardElements);
});
