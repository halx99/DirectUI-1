#pragma once

namespace DirectUI
{
	class UILIB_API CCPushButton : public CCBase
	{
	public:
		CCPushButton(const CCPushButton &);
		CCPushButton(unsigned long);
		CCPushButton & operator=(const CCPushButton &);
		
		virtual ~CCPushButton(void);

		static long __stdcall Create(unsigned int, Element *, unsigned long *, Element * *);
		static long __stdcall Create(Element *, unsigned long *, Element * *);
		static const PropertyInfo * __stdcall OverrideButtonBackgroundProp(void);
		static long __stdcall Register(void);
		static void __stdcall SetClassInfoPtr(IClassInfo *);
		static IClassInfo * __stdcall GetClassInfoPtr(void);
		static const PropertyInfo * __stdcall HasShieldProp(void);

		long SetOverrideButtonBackground(bool);
		bool GetHasShield(void);
		bool GetOverrideButtonBackground(void);

		//�����麯������
		virtual long DefaultAction(void);
		virtual IClassInfo * GetClassInfoW(void);
		virtual SIZE GetContentSize(int, int, Surface *);
		virtual void OnInput(InputEvent *);
		virtual bool OnLostDialogFocus(DialogElement *);
		virtual bool OnMessage(unsigned int, unsigned int, long, long *);
		virtual bool OnNotify(unsigned int, unsigned int, long, long *);
		virtual void OnPropertyChanged(const PropertyInfo *, int, Value *, Value *);
		virtual bool OnReceivedDialogFocus(DialogElement *);

		//1
		virtual bool GetButtonColor(HDC *, HBRUSH**);
		//2
		virtual void OnSelectedPropertyChanged(void);
		//3
		virtual SIZE EstimateContentSize(int, int, Surface *);

	protected:
		void SetDefaultState(unsigned long, unsigned long);
	private:
		static IClassInfo * s_pClassInfo;
	};
}