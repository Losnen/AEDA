  TDATO aux;
   TDATO op1;
   TDATO op2;
   TDATO operando; 
   TDATO resultado;
   char op; 
   string operador("+-*/");

   while (expresion.peek() != '=')
   {

    if(isdigit(expresion.peek()))
    {        
        expresion >> operando;
            pila_.push(operando);
    }
    
    else
    {
    
        expresion >> op;
        
        if (!isdigit(expresion.peek()))
        {
            cout << "Error al escribir en forma RPN" << endl; 
        }
        else
        {
            switch (op)
             {
                case '+':
                     op1 = pila_.pop();
                     op2 = pila_.pop();
                     aux = op1 + op2;
                     pila_.push(aux);
                     
                 break;
        
                case '-':
                     op1 = pila_.pop();
                     op2 = pila_.pop();
                     pila_.push(op2 - op1);
           
                break;
        
                case '/':
                     op1 = pila_.pop();
                     op2 = pila_.pop();
                     pila_.push(op2 / op1);
           
                break; 
         
                case '*':
                    op1 = pila_.pop();
                    op2 = pila_.pop();
                    pila_.push(op1 * op2);
        
                 break; 
        
            }
        
         }
    
    
    expresion.ignore(1);
    
  
   }
    
   
   
   
   cout << endl; 
   
    return pila_.pop(); 