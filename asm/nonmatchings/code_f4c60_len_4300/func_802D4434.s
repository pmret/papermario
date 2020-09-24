.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D4434
/* F8DE4 802D4434 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F8DE8 802D4438 AFBF0010 */  sw        $ra, 0x10($sp)
/* F8DEC 802D443C 0080282D */  daddu     $a1, $a0, $zero
/* F8DF0 802D4440 0000202D */  daddu     $a0, $zero, $zero
.L802D4444:
/* F8DF4 802D4444 3C02802E */  lui       $v0, 0x802e
/* F8DF8 802D4448 8C42B7C0 */  lw        $v0, -0x4840($v0)
/* F8DFC 802D444C 00041880 */  sll       $v1, $a0, 2
/* F8E00 802D4450 00621821 */  addu      $v1, $v1, $v0
/* F8E04 802D4454 8C620000 */  lw        $v0, ($v1)
/* F8E08 802D4458 54450005 */  bnel      $v0, $a1, .L802D4470
/* F8E0C 802D445C 24840001 */   addiu    $a0, $a0, 1
/* F8E10 802D4460 0C0B50FD */  jal       func_802D43F4
/* F8E14 802D4464 00000000 */   nop      
/* F8E18 802D4468 080B511F */  j         .L802D447C
/* F8E1C 802D446C 00000000 */   nop      
.L802D4470:
/* F8E20 802D4470 28820040 */  slti      $v0, $a0, 0x40
/* F8E24 802D4474 1440FFF3 */  bnez      $v0, .L802D4444
/* F8E28 802D4478 00000000 */   nop      
.L802D447C:
/* F8E2C 802D447C 8FBF0010 */  lw        $ra, 0x10($sp)
/* F8E30 802D4480 03E00008 */  jr        $ra
/* F8E34 802D4484 27BD0018 */   addiu    $sp, $sp, 0x18
