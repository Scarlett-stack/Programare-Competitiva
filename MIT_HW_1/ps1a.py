def downpay(annual_salary, portion_saved, total_cost):
    downp = total_cost * 0.25
    print(downp)
    r = 0.04
    current_savings = 0
    monthly = annual_salary / 12
    months = 0
    while current_savings < downp:
        current_savings = current_savings + current_savings*(r/12) + portion_saved*monthly
        months+=1
        #print(months, current_savings)

    return months

annual_salary = float(input("The starting annual salary (annual_salary)" ))
portion_saved = float(input("The portion of salary to be saved (portion_saved)"))
total_cost = float(input("The cost of your dream home (total_cost)"))
print(f'ansl : {annual_salary} portions {portion_saved} total {total_cost}')
months = downpay(annual_salary, portion_saved,total_cost)
print(months)