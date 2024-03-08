var input = '';

        function tambahAngka(value){
            input += value;
            document.getElementById('input').value = input;
        }

        function clean(){
            input = '';
            document.getElementById('input').value = input;
        }

        function calculate(){
            try{
                let result = eval(input);
                document.getElementById('input').value = result;
                input = result.toString();
            }catch(error){
                document.getElementById('input').value = 'Error';
            }
        }

        function persen(){
            try{
                let result = parseFloat(input)/100;
                document.getElementById('input').value = result;
                input = result.toString();
            }catch(error){
                document.getElementById('input').value = 'Error';
            }
        }

        function backspace() {
            input = input.slice(0, -1);
            document.getElementById('input').value = input;
        }