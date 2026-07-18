class Twitter:
        
    def __init__(self):
        self.count = 0
        self.posts = {}
        self.follows = {}
        self.activity = {}


    def postTweet(self, userId: int, tweetId: int) -> None:
        self.posts.setdefault(userId,deque())
        self.posts[userId].appendleft((self.count,tweetId))
        self.count+=1
        if len(self.posts[userId])>10:
            self.posts[userId].pop()

    def getNewsFeed(self, userId: int) -> List[int]:
        mh = []
        self.follow(userId,userId)
        for v in self.follows[userId]:
            p = self.posts.get(v,None)
            if p:
                heapq.heappush(mh,[p[0][0],p[0][1],0,v]) 
            if len(mh)>10:
                heapq.heappop(mh)  
        maxheap = []
        for v in mh:
            v[0] = -v[0]
            heapq.heappush(maxheap,v)
        ans = []
        while len(ans)<10 and len(maxheap):
            v = heapq.heappop(maxheap)
            ans.append(v[1])
            p = self.posts[v[3]]
            if v[2]+1 < len(p):
                heapq.heappush(maxheap,[-p[v[2]+1][0],p[v[2]+1][1],v[2]+1,v[3]])
        return ans
        

    def follow(self, followerId: int, followeeId: int) -> None:
        self.follows.setdefault(followerId,set())
        self.follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.follows.setdefault(followerId,set())
        if followeeId in self.follows[followerId]:
            self.follows[followerId].remove(followeeId)
