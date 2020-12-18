// example for receiving data from arduino,


// first start the virtual machine 
// go to Window => Virtual Machine Monitor
// and press "Start Virtual Machine"

// also open the Console Monitor
// go to Window => Console Monitor


SerialIO.list() @=> string list[];

for(int i; i < list.size(); i++)
{
	chout <= i <= ": " <= list[i] <= IO.newline();
}


//check on the console monitor which port number
// is the arduino and replace it
3 => int device;
if(me.args()) me.arg(0) => Std.atoi => device;

SerialIO cereal;
cereal.open(device, SerialIO.B9600, SerialIO.BINARY);

while(true)
{
	cereal.onByte() => now;
	cereal.getByte() => int byte;
	chout <= "byte: " <= byte <= IO.newline();
	
	// cereal.getByte() => Std.atoi => int intValue;
	// chout <= "int: "  <= intValue <= IO.newline();
}
