/*Facility Int_Swap_Example_Fac;
*/
#import Resolve.h
#import Integer_Template_Int.h
    /*Operation Exchange(updates I: Integer; updates J: Integer);
        ensures I = #J and J = #I;
    Procedure */

	void Int_Swap_Example_Fac_Exchange(r_type* I, r_type* J){
		instan_int();

		/*Integer_Template_Fac* _Integer_Fac;
		proc_struct* _Integer_proc;
		Integer_Template_Fac_Init(&IF_Fac);
		proc_init(&_Integer_proc, Integer_Template_Int_Init, Integer_Int_Final,
			_Integer_Fac, nullProc);*/

    /*    Var Temp: Integer;*/
		r_type* Temp;
		r_type_init(&Temp, stdIntProc);


		/*
        Temp := I;
        I := J;
        J := Temp;*/
		Integer_Template_Int_Set(Temp, I);
		Integer_Template_Int_Set(I, J);
		Integer_Template_Int_Set(J, Temp);

		/*
    end Exchange;
*/
	}
/*
    Operation Exchange2(updates I: Integer; updates J: Integer);
        ensures I = #J and J = #I;
    Procedure
    */
    void Int_Swap_Example_Fac_Exchange2(r_type* I, r_type* J){
    /*
        I := I + J;
        J := I - J;
        I := I - J;
    */
		Integer_Template_Int_Set(I, Integer_Template_Sum(I,J));
        Integer_Template_Int_Set(I, Integer_Template_Minus(I,J));

    /*
    end Exchange2;
    */

    /*
    Operation Main();
    Procedure
        Var X, Y: Integer;
        Write_Line("Input two numbers");
        Read(X);
        Read(Y);
        Exchange(X, Y);
        Write("The first number is:");
        Write(X);
        Write_Line("------------");
        Write("The second number is:");
        Write(Y);
        Write_Line("------------");
        Exchange2(X, Y);
        Write("The first number is:");
        Write(X);
        Write_Line("------------");
        Write("The second number is:");
        Write(Y);
        Write_Line("------------");
    end Main;
end Int_Swap_Example_Fac;*/
