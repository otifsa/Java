#****************************le projet de Systeme distubuee avec corba************************************
1- creation java server
	--pour lance annuaire 
	tnameserv -ORBInitialPort 1050
        start orbd -ORBInitialPort 1050

	--lance server 
	java java TransactionServer -ORBInitialPort 1050
	--lance client on local host 
	java TransactionClient -ORBInitialPort 1050 
	--lance client on distance
	java TransactionClient -ORBInitialPort 1050 -ORBItialHost 192.168.0.103

2- configuration database 
	--create table 
        **********************************************************
	* CREATE TABLE `c_transaction` (			 *
	*	  `id` int(10) unsigned NOT NULL,		 *	
	*	  `counterId` varchar(45) NOT NULL DEFAULT '',	 *
	*	 `date` varchar(45) NOT NULL DEFAULT '',	 *
	*	`amountDebit` double DEFAULT NULL,		 *
	*	`amountCredit` double DEFAULT NULL,		 *
	*	  `accountId` varchar(45) NOT NULL DEFAULT '',	 *
	*	  PRIMARY KEY (`id`)				 *
	*	)						 *
	*							 *
	**********************************************************

	--create user to for distance connections
	 CREATE USER 'oti'@'localhost' IDENTIFIED BY 'fsa';
	 GRANT ALL ON corba.*TO oti@'192.168.0.103' IDENTIFIED BY 'fsa';

	--add mysql driver to $CLASSPATH
	##sudo apt-get install libmysql-java
	##export CLASSPATH=$CLASSPATH:/usr/share/java/mysql-connector-java.jar

3-installation et configuration mico 2.3.13
 	--download mico 2.3.13 
	-- mkdir micosrc 
 	-- extarct file :tar -xvf mico-2.3.13.tar.gz
	-- edit file fast_array.cc :gedit orb/fast_array.cc add "#include<limits.h>"
	-- ./configure --prefix=$HOME/mico
	-- time make -j5 >make.log 2>make.err
	-- time make install >inst.log 2>inst.err
	-- export PATH=$PATH:$HOME/mico/bin
	-- export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/mico/lib
	-- export LIBRARY_PATH=$LIBRARY_PATH:$HOME/mico/lib
	-- export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:$HOME/mico/include

4- creation et compilation de client
	-- compile client: mico-c++ -I. -c TransactionClient.cpp -o TransactionClient.o
	-- exeute: mico-c++ -I. -c bank.cc -o Transaction.o
	-- mico-ld -o client TransactionClient.o Transaction.o -lmico2.3.13 -lmicocoss2.3.13
	-- ./client -ORBInitRef NameService=corbaloc::127.0.0.1:1050/NameService
