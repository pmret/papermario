.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80280000
/* 7E0E80 80280000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E0E84 80280004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E0E88 80280008 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E0E8C 8028000C AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E0E90 80280010 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E0E94 80280014 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E0E98 80280018 8C510144 */  lw        $s1, 0x144($v0)
/* 7E0E9C 8028001C 24050001 */  addiu     $a1, $zero, 1
/* 7E0EA0 80280020 8E220010 */  lw        $v0, 0x10($s1)
/* 7E0EA4 80280024 8C430018 */  lw        $v1, 0x18($v0)
/* 7E0EA8 80280028 00041080 */  sll       $v0, $a0, 2
/* 7E0EAC 8028002C 3C048028 */  lui       $a0, 0x8028
/* 7E0EB0 80280030 24843E80 */  addiu     $a0, $a0, 0x3e80
/* 7E0EB4 80280034 00431021 */  addu      $v0, $v0, $v1
/* 7E0EB8 80280038 8C500000 */  lw        $s0, ($v0)
/* 7E0EBC 8028003C 0C0B0CF8 */  jal       start_script
/* 7E0EC0 80280040 0000302D */   daddu    $a2, $zero, $zero
/* 7E0EC4 80280044 0040202D */  daddu     $a0, $v0, $zero
/* 7E0EC8 80280048 AC900084 */  sw        $s0, 0x84($a0)
/* 7E0ECC 8028004C 8E220010 */  lw        $v0, 0x10($s1)
/* 7E0ED0 80280050 8C420000 */  lw        $v0, ($v0)
/* 7E0ED4 80280054 AC820088 */  sw        $v0, 0x88($a0)
/* 7E0ED8 80280058 8E220010 */  lw        $v0, 0x10($s1)
/* 7E0EDC 8028005C 8C420008 */  lw        $v0, 8($v0)
/* 7E0EE0 80280060 AC82008C */  sw        $v0, 0x8c($a0)
/* 7E0EE4 80280064 8E230010 */  lw        $v1, 0x10($s1)
/* 7E0EE8 80280068 8C820144 */  lw        $v0, 0x144($a0)
/* 7E0EEC 8028006C 8C630004 */  lw        $v1, 4($v1)
/* 7E0EF0 80280070 AC830090 */  sw        $v1, 0x90($a0)
/* 7E0EF4 80280074 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E0EF8 80280078 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E0EFC 8028007C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E0F00 80280080 03E00008 */  jr        $ra
/* 7E0F04 80280084 27BD0020 */   addiu    $sp, $sp, 0x20
