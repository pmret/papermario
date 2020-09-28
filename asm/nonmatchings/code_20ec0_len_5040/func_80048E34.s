.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80048E34
/* 24234 80048E34 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 24238 80048E38 AFB00010 */  sw        $s0, 0x10($sp)
/* 2423C 80048E3C 0080802D */  daddu     $s0, $a0, $zero
/* 24240 80048E40 AFB20018 */  sw        $s2, 0x18($sp)
/* 24244 80048E44 00A0902D */  daddu     $s2, $a1, $zero
/* 24248 80048E48 AFBF001C */  sw        $ra, 0x1c($sp)
/* 2424C 80048E4C AFB10014 */  sw        $s1, 0x14($sp)
/* 24250 80048E50 8E02003C */  lw        $v0, 0x3c($s0)
/* 24254 80048E54 10400005 */  beqz      $v0, .L80048E6C
/* 24258 80048E58 00C0882D */   daddu    $s1, $a2, $zero
/* 2425C 80048E5C 8E040054 */  lw        $a0, 0x54($s0)
/* 24260 80048E60 0C0B102B */  jal       kill_script_by_ID
/* 24264 80048E64 00000000 */   nop      
/* 24268 80048E68 AE00003C */  sw        $zero, 0x3c($s0)
.L80048E6C:
/* 2426C 80048E6C 8E0200BC */  lw        $v0, 0xbc($s0)
/* 24270 80048E70 10400004 */  beqz      $v0, .L80048E84
/* 24274 80048E74 00000000 */   nop      
/* 24278 80048E78 0C0B102B */  jal       kill_script_by_ID
/* 2427C 80048E7C 8E0400C0 */   lw       $a0, 0xc0($s0)
/* 24280 80048E80 AE0000BC */  sw        $zero, 0xbc($s0)
.L80048E84:
/* 24284 80048E84 8E020024 */  lw        $v0, 0x24($s0)
/* 24288 80048E88 1040000C */  beqz      $v0, .L80048EBC
/* 2428C 80048E8C 2405000A */   addiu    $a1, $zero, 0xa
/* 24290 80048E90 0040202D */  daddu     $a0, $v0, $zero
/* 24294 80048E94 24060020 */  addiu     $a2, $zero, 0x20
/* 24298 80048E98 0C0B0CF8 */  jal       start_script
/* 2429C 80048E9C AE1100C8 */   sw       $s1, 0xc8($s0)
/* 242A0 80048EA0 0040202D */  daddu     $a0, $v0, $zero
/* 242A4 80048EA4 AE04003C */  sw        $a0, 0x3c($s0)
/* 242A8 80048EA8 8C820144 */  lw        $v0, 0x144($a0)
/* 242AC 80048EAC 86030008 */  lh        $v1, 8($s0)
/* 242B0 80048EB0 AE020054 */  sw        $v0, 0x54($s0)
/* 242B4 80048EB4 AC83014C */  sw        $v1, 0x14c($a0)
/* 242B8 80048EB8 AC900148 */  sw        $s0, 0x148($a0)
.L80048EBC:
/* 242BC 80048EBC 8E0200B8 */  lw        $v0, 0xb8($s0)
/* 242C0 80048EC0 1040000C */  beqz      $v0, .L80048EF4
/* 242C4 80048EC4 2405000A */   addiu    $a1, $zero, 0xa
/* 242C8 80048EC8 0040202D */  daddu     $a0, $v0, $zero
/* 242CC 80048ECC 24060020 */  addiu     $a2, $zero, 0x20
/* 242D0 80048ED0 0C0B0CF8 */  jal       start_script
/* 242D4 80048ED4 AE1200C4 */   sw       $s2, 0xc4($s0)
/* 242D8 80048ED8 0040202D */  daddu     $a0, $v0, $zero
/* 242DC 80048EDC AE0400BC */  sw        $a0, 0xbc($s0)
/* 242E0 80048EE0 8C820144 */  lw        $v0, 0x144($a0)
/* 242E4 80048EE4 86030008 */  lh        $v1, 8($s0)
/* 242E8 80048EE8 AE0200C0 */  sw        $v0, 0xc0($s0)
/* 242EC 80048EEC AC83014C */  sw        $v1, 0x14c($a0)
/* 242F0 80048EF0 AC900148 */  sw        $s0, 0x148($a0)
.L80048EF4:
/* 242F4 80048EF4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 242F8 80048EF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 242FC 80048EFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 24300 80048F00 8FB00010 */  lw        $s0, 0x10($sp)
/* 24304 80048F04 03E00008 */  jr        $ra
/* 24308 80048F08 27BD0020 */   addiu    $sp, $sp, 0x20
