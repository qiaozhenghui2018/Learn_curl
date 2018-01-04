from bs4 import BeautifulSoup
import urllib2

def getPage(href):
    headers = {'User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.8.1.11) Gecko/20071127 Firefox/2.0.0.11'}

    req = urllib2.Request(url = href, headers = headers)

    try:
        post = urllib2.urlopen(req)

    except urllib2.HTTPError, e:
        print e.code
        print e.reason

    return post.read()

url = 'http://kaijiang.zhcw.com/zhcw/html/ssq/list_1.html'

def getPageNum(url):
    num = 0
    page = getPage(url)
    soup = BeautifulSoup(page)
    strong = soup.find('td', colspan='7')

    print strong

    if strong:
        result = strong.get_text().split(' ')
        print result
        list_num = re.findall("[0-9]{1}", result[1])
        print list_num
        
        for i in range(len(list_num)):
            num = num*10 + int(list_num[i])

        return num
    else:
        return 0

def getText(url):
    for list_num in range(1, getPageNum(url)):
        print list_num
        
        href = 'http://kaijiang.zhcw.com/zhcw/html/ssq/list_' + str(list_num) + '.html'

        page = BeautifulSoup(getPage(url))

        em_list = page.find_all('em')
        div_list = page.find_all('td', {'align':'center'})

        n = 0

        fp = open('history.log', 'w')
        
        for div in em_list:
            text = div.get_text()
            text = text.encode('utf-8')

            n = n + 1

            if n==7:
                text = text + '\n'
                n = 0
            else:
                text = text + ','
            fp.write(str(text))
        fp.close()

getText(url)

