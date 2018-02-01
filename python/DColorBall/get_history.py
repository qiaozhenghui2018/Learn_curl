from bs4 import BeautifulSoup
import urllib2

def getPage(href):
    
    headers = {u'User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.8.1.11) Gecko/20071124 Firefox/3.0.0.11'}
    
    '''headers = {}
    '''
    '''
    print('get page url =', href)
    '''
    req = urllib2.Request(url = href)

    try:
        post = urllib2.urlopen(req)

    except urllib2.HTTPError as e:
        print(e.code)
        print(e.reason)

    return post.read()

url = u'http://kaijiang.zhcw.com/zhcw/html/ssq/list_1.html'

def getPageNum(url):
    num = 0
    page = getPage(url)
    soup = BeautifulSoup(page)
    strong = soup.find('td', colspan='7')

    print("strong=",strong)

    if strong:
        result = strong.get_text().split(' ')
        print('result=',result)
        return 111
        list_num = result.find("[0-9]{1}", result[1])
        print(list_num)
        
        for i in range(len(list_num)):
            num = num*10 + int(list_num[i])

        return num
    else:
        return 0

def getText(url):
    
    for list_num in range(1, getPageNum(url)+1):
        '''
        print(list_num)
        '''
        href = u'http://kaijiang.zhcw.com/zhcw/html/ssq/list_' + str(list_num) + '.html'
        print('href = ', href)

        page = BeautifulSoup(getPage(href))
        '''
        print('page=', page)
        '''
        em_list = page.find_all('em')
        date_list = page.find_all('td', {'align':'center'})
        '''
        div_list = page.find_all('td', {'align':'center'})
        '''
        '''
        print('em_list', em_list)
        print('div_list', div_list)
        '''
        '''
        print(date_list)
        '''
        n = 0
        m = 0
        for div in em_list:
            text = div.get_text()
            text = text.encode('utf-8')

            n = n + 1
            '''print (date_list[5*m])
            '''
            m += 1
            
            if n==7:
                text = text + '\n'
                n = 0
            else:
                text = text +  ','
            fp.write(str(text))

fp = open('history.log', 'w')
getText(url)
fp.close()
