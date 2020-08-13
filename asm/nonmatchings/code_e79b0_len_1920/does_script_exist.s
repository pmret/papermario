.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel does_script_exist
/* 0E8B14 802C4164 0000282D */  daddu $a1, $zero, $zero
/* 0E8B18 802C4168 3C03802E */  lui   $v1, 0x802e
/* 0E8B1C 802C416C 8C63A890 */  lw    $v1, -0x5770($v1)
.L802C4170:
/* 0E8B20 802C4170 8C620000 */  lw    $v0, ($v1)
/* 0E8B24 802C4174 10400006 */  beqz  $v0, .L802C4190
/* 0E8B28 802C4178 24A50001 */   addiu $a1, $a1, 1
/* 0E8B2C 802C417C 8C420144 */  lw    $v0, 0x144($v0)
/* 0E8B30 802C4180 14440004 */  bne   $v0, $a0, .L802C4194
/* 0E8B34 802C4184 28A20080 */   slti  $v0, $a1, 0x80
/* 0E8B38 802C4188 03E00008 */  jr    $ra
/* 0E8B3C 802C418C 24020001 */   addiu $v0, $zero, 1

.L802C4190:
/* 0E8B40 802C4190 28A20080 */  slti  $v0, $a1, 0x80
.L802C4194:
/* 0E8B44 802C4194 1440FFF6 */  bnez  $v0, .L802C4170
/* 0E8B48 802C4198 24630004 */   addiu $v1, $v1, 4
/* 0E8B4C 802C419C 03E00008 */  jr    $ra
/* 0E8B50 802C41A0 0000102D */   daddu $v0, $zero, $zero

