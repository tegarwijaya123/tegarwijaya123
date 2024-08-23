document.addEventListener('alpine:init', () => {
    Alpine.data('products', () => ({
        
        items: [
            {id: 1, name: 'Jaket kulit', img: 'produk2.jpg', price: 400000 },
            {id: 2, name: 'Flanel hitam ', img: 'produk4.jpg', price: 150000 },
            {id: 3, name: 'Jakey denim', img: 'produk5.jpg', price: 500000 },
            {id: 4, name: 'Sweater', img: 'produk6.jpg', price: 250000 },
        ],
        init() {
            // Call feather.replace() after Alpine.js renders the elements
            this.$nextTick(() => {
              feather.replace();
            });
          }
    }));


    Alpine.store('cart', {
      items: [],
      total: 0,
      quantity: 0,
      add(newItem) {
        // cek barang yang asama
        const cartItem = this.items.find((item) => item.id === newItem.id);

        // jika belum ada
        if(!cartItem){
          this.items.push({...newItem, quantity: 1, total: newItem.price });
          this.quantity++;
          this.total += newItem.price;
          
        }else {
          this.items = this.items.map((item)=> {
            if(item.id !== newItem.id){
              return item;
            } else {
              item.quantity++;
              item.total = item.price * item.quantity;
              this.quantity++;
              this.total += item.price;
              return item;
            }
          })
        }
      },

      remove(id){
        const cartItem = this.items.find((item) => item.id === id);
        if(cartItem.quantity > 1){
          this.items = this.items.map((item) => {
            if(item.id !== id){
              return item;
            } else {
              item.quantity--;
              item.total = item.price * item.quantity;
              this.quantity--;
              this.total -= item.price
              return item;
            }
          })
        } else if (cartItem.quantity === 1){
          this.items = this.items.filter((item) => item.id !== id);
          this.quantity--;
          this.total -= cartItem.price;
        }
      }

    });
});


// konversi ke rupiah

const rupiah = (number) => {
  return new Intl.NumberFormat('id-ID', {
    style: 'currency',
    currency:'IDR',
    minimumFractionDigits: 0,

  }).format(number);
}



