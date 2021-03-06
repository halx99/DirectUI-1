#pragma once

namespace DirectUI
{
	class UILIB_API CCCheckBox :public CCBaseCheckRadioButton
	{
	public:
		CCCheckBox(const CCCheckBox &);
		CCCheckBox(unsigned long);
		CCCheckBox & operator=(const CCCheckBox &);
		virtual ~CCCheckBox(void);

		static long __stdcall Create(unsigned int, Element *, unsigned long *, Element * *);
		static long __stdcall Create(Element *, unsigned long *, Element * *);
		static long __stdcall Register(void);
		static void __stdcall SetClassInfoPtr(IClassInfo *);
		static IClassInfo * __stdcall GetClassInfoPtr(void);

		virtual IClassInfo * GetClassInfoW(void);
		virtual void OnInput(InputEvent *);
		virtual bool OnNotify(unsigned int, unsigned int, long, long *);

	private:
		static IClassInfo * s_pClassInfo;
	};
}