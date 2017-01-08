#****************************le projet de Systeme distubuee avec corba************************************
1- creation java server
	--pour lance annuaire 
	tnameserv -ORBInitialPort 1050
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
3-




