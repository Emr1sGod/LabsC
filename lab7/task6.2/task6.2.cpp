﻿#include <iostream>
#include "mp3All.cpp"
#include "functions.h"
using namespace std;

int main()
{
	mp3All mp;
	mp.addCompositions();
	mp.addAlbums();
	mp.addArtists();
	mp.addMusicalDirections();
	while (1) {
		cout << "Welcome to the online store mp3All.com!\n";
		int i = 0;
		for (musicalDirection tempMusicalDirection : mp.getAllMusicalDirections()) {
			i++;
			cout << i << ". " << tempMusicalDirection.getName() << endl;
		}
		cout << i + 1 << ". Proceed to payment\n";
		cout << i + 2 << ". Exit\n";
		int choice = inputCheck(i + 2);
		if (choice == i + 1) {
			cout << "Albums in cart:";
			for (album tempAlbum : *mp.getShopCart()->getAlbums()) {
				cout << " " << tempAlbum.getName();
			}
			cout << endl;
			cout << "Compositions in cart:";
			for (composition tempComposition : *mp.getShopCart()->getCompositions()) {
				cout << " " << tempComposition.getName();
			}
			cout << endl;
			cout << "For payment: " << *mp.getShopCart()->getPrice() << endl;
			cout << "Enter bank card number: ";
			string bankCard;
			getline(cin, bankCard);
			getline(cin, bankCard);
			system("cls");
			cout << "Payment was successful\n";
			*mp.getRevenue() += *mp.getShopCart()->getPrice();
			cout << "1. Back\n";
			choice = inputCheck(1);
			continue;
		}
		else if (choice == i + 2) {
			cout << "Count compositions: " << mp.getCountCompositions() << endl;
			cout << "Count compositions sold: " << *mp.getCountCompositionsSold() << endl;
			cout << "Store revenue: " << *mp.getRevenue() << endl;
			return 0;
		}
		else {
			i = 0;
			for (musicalDirection tempMusicalDirection : mp.getAllMusicalDirections()) {
				i++;
				if (choice == i) {
					while (1) {
						cout << "1. List of artists\n";
						cout << "2. About " << tempMusicalDirection.getName() << endl;
						cout << "3. Back\n";
						choice = inputCheck(3);
						if (choice == 2) {
							cout << tempMusicalDirection.getInfo() << endl;
							cout << "1. Back\n";
							choice = inputCheck(1);
							continue;
						}
						else if (choice == 3) {
							break;
						}
						else {
							while (1) {
								i = 0;
								for (artist tempArtist : tempMusicalDirection.getArtists()) {
									i++;
									cout << i << ". " << tempArtist.getName() << endl;
								}
								cout << i + 1 << ". Back\n";
								choice = inputCheck(i + 1);
								if (choice == i + 1) {
									break;
								}
								else {
									i = 0;
									for (artist tempArtist : tempMusicalDirection.getArtists()) {
										i++;
										if (choice == i) {
											while (1) {
												cout << "1. List of albums\n";
												cout << "2. List of compositions\n";
												cout << "3. About " << tempArtist.getName() << endl;
												cout << "4. Back\n";
												choice = inputCheck(4);
												if (choice == 3) {
													cout << tempArtist.getInfo() << endl;
													cout << "1. Back\n";
													choice = inputCheck(1);
													continue;
												}
												else if (choice == 4) {
													break;
												}
												else if (choice == 1) {
													while (1) {
														i = 0;
														for (album tempAlbum : tempArtist.getAlbums()) {
															i++;
															cout << i << ". " << tempAlbum.getName() << endl;
														}
														cout << i + 1 << ". Back\n";
														choice = inputCheck(i + 1);
														if (choice == i + 1) {
															break;
														}
														else {
															i = 0;
															for (album tempAlbum : tempArtist.getAlbums()) {
																i++;
																if (choice == i) {
																	while (1) {
																		i = 0;
																		for (composition tempComposition : tempAlbum.getCompositions()) {
																			i++;
																			cout << i << ". " << tempComposition.getName() << endl;
																		}
																		cout << i + 1 << ". Add album to cart\n";
																		cout << i + 2 << ". Back\n";
																		choice = inputCheck(i + 2);
																		if (choice == i + 2) {
																			break;
																		}
																		else if (choice == i + 1) {
																			cout << "Album was added to cart\n";
																			cout << "1. Back\n";
																			mp.getShopCart()->getAlbums()->push_back(tempAlbum);
																			*mp.getCountCompositionsSold() += i;
																			*mp.getShopCart()->getPrice() += tempAlbum.getPrice();
																			choice = inputCheck(1);
																			continue;
																		}
																		else {
																			i = 0;
																			for (composition tempComposition : tempAlbum.getCompositions()) {
																				i++;
																				if (choice == i) {
																					while (1) {
																						cout << "1. Add to cart\n";
																						cout << "2. " << tempComposition.getName() << "'s text\n";
																						cout << "3. Back\n";
																						choice = inputCheck(3);
																						if (choice == 2) {
																							cout << tempComposition.getText() << endl;
																							cout << "1. Back\n";
																							choice = inputCheck(1);
																							continue;
																						}
																						else if (choice == 3) {
																							break;
																						}
																						else {
																							cout << "Composition was added to cart\n";
																							cout << "1. Back\n";
																							mp.getShopCart()->getCompositions()->push_back(tempComposition);
																							*mp.getCountCompositionsSold() += 1;
																							*mp.getShopCart()->getPrice() += tempComposition.getPrice();
																							choice = inputCheck(1);
																							continue;
																						}
																					}
																				}
																				else {
																					continue;
																				}
																				break;
																			}
																		}
																	}
																}
																else {
																	continue;
																}
																break;
															}
														}
													}
												}
												else {
													while (1) {
														i = 0;
														for (composition tempComposition : tempArtist.getCompositions()) {
															i++;
															cout << i << ". " << tempComposition.getName() << endl;
														}
														cout << i + 1 << ". Back\n";
														choice = inputCheck(i + 1);
														if (choice == i + 1) {
															break;
														}
														else {
															i = 0;
															for (composition tempComposition : tempArtist.getCompositions()) {
																i++;
																if (choice == i) {
																	while (1) {
																		cout << "1. Add to cart\n";
																		cout << "2. " << tempComposition.getName() << "'s text\n";
																		cout << "3. Back\n";
																		choice = inputCheck(3);
																		if (choice == 2) {
																			cout << tempComposition.getText() << endl;
																			cout << "1. Back\n";
																			choice = inputCheck(1);
																			continue;
																		}
																		else if (choice == 3) {
																			break;
																		}
																		else {
																			cout << "Composition was added to cart\n";
																			cout << "1. Back\n";
																			mp.getShopCart()->getCompositions()->push_back(tempComposition);
																			*mp.getCountCompositionsSold() += 1;
																			*mp.getShopCart()->getPrice() += tempComposition.getPrice();
																			choice = inputCheck(1);
																			continue;
																		}
																	}
																}
																else {
																	continue;
																}
																break;
															}
														}
													}
												}
											}
										}
										else {
											continue;
										}
										break;
									}
								}
							}
						}
					}
				}
				else {
					continue;
				}
				break;
			}
		}
	}
}