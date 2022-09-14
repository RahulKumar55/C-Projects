#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double sp, mp, lp, st, tax, tot;
	int nosp, nost, noss, isp, imp, ilp;
	int stp, stt, sts, taxp, taxt, taxs, tp, tt, ts;

	printf("Set Shirt Prices\n================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf(" %lf", &sp);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf(" %lf", &mp);
	printf("Enter the price for a LARGE shirt: $");
	scanf(" %lf", &lp);

	printf("\nShirt Store Price List\n======================\n");
	printf("SMALL  : $%.2lf\n", sp);
	printf("MEDIUM : $%.2lf\n", mp);
	printf("LARGE  : $%.2lf\n", lp);

	isp = sp * 100;
	imp = mp * 100;
	ilp = lp * 100;

	printf("\nPatty's shirt size is 'S'\n");
	printf("Number of shirts Patty is buying: ");
	scanf(" %d", &nosp);
	printf("\nTommy's shirt size is 'L'\n");
	printf("Number of shirts Tommy is buying: ");
	scanf(" %d", &nost);
	printf("\nSally's shirt size is 'M'\n");
	printf("Number of shirts Sally is buying: ");
	scanf(" %d", &noss);

	stp = isp * nosp;
	stt = ilp * nost;
	sts = imp * noss;
	taxp = ((stp * 0.13) + 0.5);
	taxt = ((stt * 0.13) + 0.5);
	taxs = ((sts * 0.13) + 0.5);
	tp = stp + taxp;
	tt = stt + taxt;
	ts = sts + taxs;
	st = (stp + stt + sts) / 100.;
	tax = (taxp + taxt + taxs) / 100.;
	tot = (tp + tt + ts) / 100.;


	printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 'S', sp, nosp, stp / 100., taxp / 100., tp / 100.);
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 'M', mp, noss, sts / 100., taxs / 100., ts / 100.);
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 'L', lp, nost, stt / 100., taxt / 100., tt / 100.);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("%33.4lf %9.4lf %9.4lf\n\n", st, tax, tot);


	int stcents = (int)(st * 100);
	int too1 = stcents % 200;
	int loo1 = too1 % 100;
	int qua1 = loo1 % 25;
	int dime1 = qua1 % 10;
	int nic1 = dime1 % 5;
	int pen1 = nic1 % 1;

	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n\n");
	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n%22.4lf\n", st);
	printf("Toonies  %3d %9.4lf\n", stcents / 200, too1 / 100.);
	printf("Loonies  %3d %9.4lf\n", too1 / 100, loo1 / 100.);
	printf("Quarters %3d %9.4lf\n", loo1 / 25, qua1 / 100.);
	printf("Dimes    %3d %9.4lf\n", qua1 / 10, dime1 / 100.);
	printf("Nickels  %3d %9.4lf\n", dime1 / 5, nic1 / 100.);
	printf("Pennies  %3d %9.4lf\n", nic1 / 1, pen1 / 100.);
	printf("\nAverage cost/shirt: $%7.4lf\n\n", st/(nosp + noss + nost));

	int totcents = (int)(tot * 100);
	int too2 = totcents % 200;
	int loo2 = too2 % 100;
	int qua2 = loo2 % 25;
	int dime2 = qua2 % 10;
	int nic2 = dime2 % 5;
	int pen2 = nic2 % 1;

	
	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n%22.4lf\n", tot);
	printf("Toonies  %3d %9.4lf\n", totcents / 200, too2 / 100.);
	printf("Loonies  %3d %9.4lf\n", too2 / 100, loo2 / 100.);
	printf("Quarters %3d %9.4lf\n", loo2 / 25, qua2 / 100.);
	printf("Dimes    %3d %9.4lf\n", qua2 / 10, dime2 / 100.);
	printf("Nickels  %3d %9.4lf\n", dime2 / 5, nic2 / 100.);
	printf("Pennies  %3d %9.4lf\n", nic2 / 1, pen2 / 100.);
	printf("\nAverage cost/shirt: $%7.4lf\n", tot / (nosp + noss + nost));



	return 0;
}