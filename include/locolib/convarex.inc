#if defined _locolib_convarex_included
 #endinput
#endif
#define _locolib_convarex_included

#include "../locolib"

methodmap ConVarEx < ConVar {
	/**
	 * 	Register a new ConVar.
	 *  
	 * 	@param name					Уникальный идентификатор.
	 * 	@param defValue				Значение по умолчанию.
	 * 	@param changeHook			Хук изменения состояния.
	 * 	@param description			Описание.
	 * 	@param flags				Флаги, смотрите константы FCVAR_*
	 * 	@param hasMin				Активный ли нижний лимит?
	 * 	@param minValue				Нижний лимит.
	 * 	@param hasMax				Активный ли верхний лимит?
	 * 	@param maxValue				Верхний лимит.
	 * 
	 * 	@return Handle from the new ConVar.
	 */
	public ConVarEx(const char[] name, const char[] defValue, ConVarChanged changeHook = INVALID_FUNCTION, const char[] description = "", int flags = 0, bool hasMin = false, float minValue = 0.0, bool hasMax = false, float maxValue = 0.0) {
		ConVar cvar = CreateConVar(name, defValue, description, flags, hasMin, minValue, hasMax, maxValue);

		if(changeHook != INVALID_FUNCTION) {
			cvar.AddChangeHook(changeHook);

			Call_StartFunction(null, changeHook);
			Call_PushCell(cvar);
			Call_PushString(defValue);
			Call_PushString(defValue);
			Call_Finish();
		}

		return view_as<ConVarEx>(cvar);
	}
}