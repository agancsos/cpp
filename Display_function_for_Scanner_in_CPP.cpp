//Display buffer and character input
void display(int input)
{
	static char *message[]={\"Reserved\",\"Reserved\",\"Reserved\",\"Reserved\",\"\",\"\",\"\",\"\",\"\",\"\",
				\"Identifier\",\"Comment\",\"Real Constant\",\"String Constant\",\"Plus\",\"Minus\",
				\"Multiplication\",\"Assignment\",\"Left Parenthesis\",\"Comma\",\"Semicolon\",
				\"Right Parenthesis\",\"Left Brace\",\"Right Brace\",\"Invalid Character\",\"Integer\",\"Division\"};

	cout.setf(ios::left);
        cout << message[input];
        cout << buffer;
        cout << endl;
}
