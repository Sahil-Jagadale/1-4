#!/bin/bash

while true; do
	echo "1.CREATE DATABASE"
	echo "2.INSERT"
	echo "3.SEARCH"
	echo "4.DISPLAY"
	echo "5.DELETE"
	echo "6.UPDATE"
	echo "7.EXIT"
	echo "Enter your choice:"
	read ch;
	case "$ch" in
	1)
		echo "Enter the name of the database: "
		read db
		if [ -f "$db" ]; then
			echo "File already exists"
		else
			touch $db
			echo "File created succesfully!"
		fi
		;;
	2)
		echo "Enter the name of db in which you have to insert: "
		read db
		if [ -f "$db" ]; then
			echo "Enter the stuident ID: "
			read sd
			echo "Enter the student name: "
			read na
			while true; do
				echo "Enter the phone number: "
				read ph
				if [[ ! "$ph" =~ ^[0-9]{10}$ ]]; then
					echo "Invalid number!"
				else
					break;
				fi
			done
			echo "Enter your email: "
			read ea
			record="$sd $na $ph $ea"
			echo $record >> $db
			echo "Data Inserted!"
		else
			echo "DB doesnt exits"
		fi
				
		;;
	3)
		echo "Enter the db in which you want to search: "
		read db
		if [ -f "$db" ]; then
			echo "Enter the student id which you want to search: "
			read sid
			data=$(grep "^$sid" $db)
			if [ -z "$data" ];then 
				echo "Record not found"
			else
				echo "Record found"
				echo "$data"
			fi
		else 
			echo "DB doesnt exists"
		fi
		;;
	4)
		echo "Enter name of the db which you have display: "
		read db
		if [ -f "$db" ];then
			cat $db
		else
			echo "DB doesnt exist!"
		fi
		;;
	5)
		echo "Enter the db in which you want to delete: "
		read db
		if [ -f "$db" ]; then
			echo "Enter the student id which you want to delete: "
			read did
			if grep -q "^$did" "$db";then
				grep -v "^$did" "$db" > temp_db && mv temp_db "$db"
				echo "Record deleted!"
			else
				echo "Record not found!"
			fi
		else
			echo "DB not found"
		fi
		;;
	6)
		echo "Enter the db in which you want to update: "
		read db
		if [ -f "$db" ]; then
			echo "Enter the student id which you want to update: "
			read uid
			if grep -q "^$uid" "$db";then
				echo "Enter the field you want to update: \nName\nPhone\nEmail\n"
				read ch
				case "$ch" in
				Name)
					echo "Enter new name: "
					read na
					sed -i "s/^$uid [^ ]*/$uid $na/" "$db"
					echo "Data updated!"
					;;
				Phone)
					while true; do
						echo "Enter the new phone number: "
						read ph
						if [[ ! "$ph" =~ ^[0-9]{10}$ ]]; then
							sed -i "s/^$uid [^ ]* [^ ]*/$uid $ph/" "$db"
						else
							break;
						fi
					done
					;;
				Email)
					echo "Enter new email: "
					read ea
					sed -i "s/^$uid [^ ]* [^ ]* [^ ]*/$uid $ea/" "$db"
					echo "Data updated!"
					;;
				*) 
					echo "Invalid field!"
				esac
			else
				echo "Record not found!"
			fi
		else
			echo "DB not found!"
		fi						
		;;
	7)
		echo "exiting.."
		exit 0
		;;
	esac
	
done


