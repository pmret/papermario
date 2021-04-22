.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266F8C
/* 19586C 80266F8C 8C8401F4 */  lw        $a0, 0x1f4($a0)
/* 195870 80266F90 1080000F */  beqz      $a0, .L80266FD0
/* 195874 80266F94 3C060010 */   lui      $a2, 0x10
/* 195878 80266F98 34C60001 */  ori       $a2, $a2, 1
.L80266F9C:
/* 19587C 80266F9C 8C8500C0 */  lw        $a1, 0xc0($a0)
/* 195880 80266FA0 8C830000 */  lw        $v1, ($a0)
/* 195884 80266FA4 00661024 */  and       $v0, $v1, $a2
/* 195888 80266FA8 14400006 */  bnez      $v0, .L80266FC4
/* 19588C 80266FAC 00000000 */   nop
/* 195890 80266FB0 8C820094 */  lw        $v0, 0x94($a0)
/* 195894 80266FB4 10400003 */  beqz      $v0, .L80266FC4
/* 195898 80266FB8 30620002 */   andi     $v0, $v1, 2
/* 19589C 80266FBC 50400001 */  beql      $v0, $zero, .L80266FC4
/* 1958A0 80266FC0 A0A00750 */   sb       $zero, 0x750($a1)
.L80266FC4:
/* 1958A4 80266FC4 8C84000C */  lw        $a0, 0xc($a0)
/* 1958A8 80266FC8 1480FFF4 */  bnez      $a0, .L80266F9C
/* 1958AC 80266FCC 00000000 */   nop
.L80266FD0:
/* 1958B0 80266FD0 03E00008 */  jr        $ra
/* 1958B4 80266FD4 00000000 */   nop
