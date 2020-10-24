.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CC8_8D31D8
/* 8D31D8 80241CC8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8D31DC 80241CCC AFB00010 */  sw        $s0, 0x10($sp)
/* 8D31E0 80241CD0 0080802D */  daddu     $s0, $a0, $zero
/* 8D31E4 80241CD4 3C05FD05 */  lui       $a1, 0xfd05
/* 8D31E8 80241CD8 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8D31EC 80241CDC AFBF0020 */  sw        $ra, 0x20($sp)
/* 8D31F0 80241CE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8D31F4 80241CE4 AFB20018 */  sw        $s2, 0x18($sp)
/* 8D31F8 80241CE8 0C0B1EAF */  jal       get_variable
/* 8D31FC 80241CEC AFB10014 */   sw       $s1, 0x14($sp)
/* 8D3200 80241CF0 0200202D */  daddu     $a0, $s0, $zero
/* 8D3204 80241CF4 3C05FD05 */  lui       $a1, 0xfd05
/* 8D3208 80241CF8 34A50F8B */  ori       $a1, $a1, 0xf8b
/* 8D320C 80241CFC 0C0B1EAF */  jal       get_variable
/* 8D3210 80241D00 0040902D */   daddu    $s2, $v0, $zero
/* 8D3214 80241D04 0200202D */  daddu     $a0, $s0, $zero
/* 8D3218 80241D08 3C05FD05 */  lui       $a1, 0xfd05
/* 8D321C 80241D0C 34A50F8C */  ori       $a1, $a1, 0xf8c
/* 8D3220 80241D10 0C0B1EAF */  jal       get_variable
/* 8D3224 80241D14 0040982D */   daddu    $s3, $v0, $zero
/* 8D3228 80241D18 8E440004 */  lw        $a0, 4($s2)
/* 8D322C 80241D1C 0C048D70 */  jal       func_801235C0
/* 8D3230 80241D20 0040882D */   daddu    $s1, $v0, $zero
/* 8D3234 80241D24 0C00AB4B */  jal       heap_free
/* 8D3238 80241D28 0240202D */   daddu    $a0, $s2, $zero
/* 8D323C 80241D2C 0C00AB4B */  jal       heap_free
/* 8D3240 80241D30 0260202D */   daddu    $a0, $s3, $zero
/* 8D3244 80241D34 0C00AB4B */  jal       heap_free
/* 8D3248 80241D38 0220202D */   daddu    $a0, $s1, $zero
/* 8D324C 80241D3C 0200202D */  daddu     $a0, $s0, $zero
/* 8D3250 80241D40 3C05FD05 */  lui       $a1, 0xfd05
/* 8D3254 80241D44 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8D3258 80241D48 0C0B2026 */  jal       set_variable
/* 8D325C 80241D4C 0000302D */   daddu    $a2, $zero, $zero
/* 8D3260 80241D50 0200202D */  daddu     $a0, $s0, $zero
/* 8D3264 80241D54 3C05FD05 */  lui       $a1, 0xfd05
/* 8D3268 80241D58 34A50F8B */  ori       $a1, $a1, 0xf8b
/* 8D326C 80241D5C 0C0B2026 */  jal       set_variable
/* 8D3270 80241D60 0000302D */   daddu    $a2, $zero, $zero
/* 8D3274 80241D64 0200202D */  daddu     $a0, $s0, $zero
/* 8D3278 80241D68 3C05FD05 */  lui       $a1, 0xfd05
/* 8D327C 80241D6C 34A50F8C */  ori       $a1, $a1, 0xf8c
/* 8D3280 80241D70 0C0B2026 */  jal       set_variable
/* 8D3284 80241D74 0000302D */   daddu    $a2, $zero, $zero
/* 8D3288 80241D78 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8D328C 80241D7C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8D3290 80241D80 8FB20018 */  lw        $s2, 0x18($sp)
/* 8D3294 80241D84 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D3298 80241D88 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D329C 80241D8C 24020002 */  addiu     $v0, $zero, 2
/* 8D32A0 80241D90 03E00008 */  jr        $ra
/* 8D32A4 80241D94 27BD0028 */   addiu    $sp, $sp, 0x28
/* 8D32A8 80241D98 00000000 */  nop       
/* 8D32AC 80241D9C 00000000 */  nop       
