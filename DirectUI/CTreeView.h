#pragma once

namespace DirectUI
{
	class UILIB_API CCTreeView : public CCBase
	{
	public:
		CCTreeView(CCTreeView const &);
		CCTreeView(unsigned long);
		virtual~CCTreeView(void);
		CCTreeView &operator=(CCTreeView const &);
		
		static long __stdcall Create(unsigned int, Element *, unsigned long *, Element * *);
		static long __stdcall Create(Element *, unsigned long *, Element * *);
		static IClassInfo * __stdcall GetClassInfoPtr(void);
		static long __stdcall Register(void);
		static void __stdcall SetClassInfoPtr(IClassInfo *);
		
		HTREEITEM InsertItem(unsigned short *, unsigned int, const HTREEITEM, const HTREEITEM);
		HTREEITEM InsertItem(const TVINSERTSTRUCTW *);
		unsigned int GetItemState(HTREEITEM  const);
		unsigned long GetStyle(void);
		void SetItemState(HTREEITEM, unsigned int);

		virtual IClassInfo *GetClassInfoW(void);
		virtual SIZE GetContentSize(int, int, Surface *);
		virtual bool OnNotify(unsigned int, unsigned int, long, long *);
		unsigned long SetStyle(unsigned long);

	protected:
		//1
		virtual long _OnGetInfoTip(const LPNMTVGETINFOTIPW);
		//2
		virtual long _OnItemChanged(const NMTVITEMCHANGE*);

	private:
		static IClassInfo * s_pClassInfo;
	};
}