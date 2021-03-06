#pragma once

namespace DirectUI
{
	class UILIB_API InvokeHelper : public RefcountBase
	{
	public:
		InvokeHelper(void);
		virtual ~InvokeHelper(void);

		long DoInvoke(int, ElementProvider *, ProviderProxy * (__stdcall*)(Element *), char *);
		int Init(unsigned long);
		void Uninit(void);

	private:
		static int __stdcall _WndProc(void *, HWND, unsigned int, unsigned int, long, long *);
		static unsigned int const s_uInvokeHelperMsg;

		void OnInvoke(class InvokeArgs *);

	};


	class UILIB_API InvokeManager
	{
	public:
		InvokeManager& operator=(InvokeManager const &);
		static void __stdcall Close(void);
		static void __stdcall CloseThread(void);
		static long __stdcall GetInvokeHelper(InvokeHelper * *);
		static long __stdcall Init(void);

	private:
		static InvokeHelper * __stdcall FindInvokeHelper(unsigned int *);
	};

	class InvokeProvider : public PatternProvider<InvokeProvider, IInvokeProvider, 0>
	{
	public:
		InvokeProvider(void);
		virtual ~InvokeProvider(void);

		virtual unsigned long __stdcall AddRef(void);
		virtual ProviderProxyCall __stdcall GetProxyCreator(void);
		virtual long __stdcall Invoke(void);
		virtual long __stdcall QueryInterface(GUID const &, void * *);
		virtual unsigned long __stdcall Release(void);
	};

	//推测DoMethod 以及Init 来自一个纯虚类……，但是目前没有直接证据
	class UILIB_API InvokeProxy
	{
	public:
		InvokeProxy(InvokeProxy const &);
		InvokeProxy(void);
		InvokeProxy & operator=(InvokeProxy const &);

		static InvokeProxy * __stdcall Create(Element *);
		static bool __stdcall IsPatternSupported(Element *);

		virtual long DoMethod(int, char *);

	protected:
		virtual void Init(Element *);
	};
}