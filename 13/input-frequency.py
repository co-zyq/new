sentence = input("enter a sentence:")
counter={}
for ch in sentence:
    if 'A' <= ch <= 'Z' or 'a' <= ch <= 'z':
        counter[ch] = counter.get(ch,0)+1
ecounter = sorted(counter,key=counter.get,reverse=True)
for ch in ecounter:
    print(f'{ch}: {counter[ch]}')

