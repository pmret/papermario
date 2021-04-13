.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_npc_safe
/* 15F48 8003AB48 0000182D */  daddu     $v1, $zero, $zero
/* 15F4C 8003AB4C 3C06800A */  lui       $a2, %hi(gCurrentNpcListPtr)
/* 15F50 8003AB50 8CC60B90 */  lw        $a2, %lo(gCurrentNpcListPtr)($a2)
.L8003AB54:
/* 15F54 8003AB54 8CC50000 */  lw        $a1, ($a2)
/* 15F58 8003AB58 50A00008 */  beql      $a1, $zero, .L8003AB7C
/* 15F5C 8003AB5C 24630001 */   addiu    $v1, $v1, 1
/* 15F60 8003AB60 8CA20000 */  lw        $v0, ($a1)
/* 15F64 8003AB64 50400005 */  beql      $v0, $zero, .L8003AB7C
/* 15F68 8003AB68 24630001 */   addiu    $v1, $v1, 1
/* 15F6C 8003AB6C 80A200A4 */  lb        $v0, 0xa4($a1)
/* 15F70 8003AB70 50440006 */  beql      $v0, $a0, .L8003AB8C
/* 15F74 8003AB74 28630040 */   slti     $v1, $v1, 0x40
/* 15F78 8003AB78 24630001 */  addiu     $v1, $v1, 1
.L8003AB7C:
/* 15F7C 8003AB7C 28620040 */  slti      $v0, $v1, 0x40
/* 15F80 8003AB80 1440FFF4 */  bnez      $v0, .L8003AB54
/* 15F84 8003AB84 24C60004 */   addiu    $a2, $a2, 4
/* 15F88 8003AB88 28630040 */  slti      $v1, $v1, 0x40
.L8003AB8C:
/* 15F8C 8003AB8C 10600002 */  beqz      $v1, .L8003AB98
/* 15F90 8003AB90 0000102D */   daddu    $v0, $zero, $zero
/* 15F94 8003AB94 00A0102D */  daddu     $v0, $a1, $zero
.L8003AB98:
/* 15F98 8003AB98 03E00008 */  jr        $ra
/* 15F9C 8003AB9C 00000000 */   nop
