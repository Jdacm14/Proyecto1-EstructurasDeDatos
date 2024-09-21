#pragma once
#include<string>

struct Nodo {
	std::string url;
	std::string titulo;
	Nodo* prev;
	Nodo* next;

	Nodo(const std::string& url, const std::string& title)
		:url(url), titulo(title), prev(nullptr), next(nullptr){}
};
