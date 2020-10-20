.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024353C
/* A96C7C 8024353C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A96C80 80243540 AFBF0014 */  sw        $ra, 0x14($sp)
/* A96C84 80243544 AFB00010 */  sw        $s0, 0x10($sp)
/* A96C88 80243548 8C900148 */  lw        $s0, 0x148($a0)
/* A96C8C 8024354C 0C00EABB */  jal       get_npc_unsafe
/* A96C90 80243550 86040008 */   lh       $a0, 8($s0)
/* A96C94 80243554 0040202D */  daddu     $a0, $v0, $zero
/* A96C98 80243558 8E03006C */  lw        $v1, 0x6c($s0)
/* A96C9C 8024355C 24020002 */  addiu     $v0, $zero, 2
/* A96CA0 80243560 14620003 */  bne       $v1, $v0, .L80243570
/* A96CA4 80243564 00000000 */   nop      
/* A96CA8 80243568 AC80001C */  sw        $zero, 0x1c($a0)
/* A96CAC 8024356C AC800018 */  sw        $zero, 0x18($a0)
.L80243570:
/* A96CB0 80243570 8FBF0014 */  lw        $ra, 0x14($sp)
/* A96CB4 80243574 8FB00010 */  lw        $s0, 0x10($sp)
/* A96CB8 80243578 24020002 */  addiu     $v0, $zero, 2
/* A96CBC 8024357C 03E00008 */  jr        $ra
/* A96CC0 80243580 27BD0018 */   addiu    $sp, $sp, 0x18
/* A96CC4 80243584 00000000 */  nop       
/* A96CC8 80243588 00000000 */  nop       
/* A96CCC 8024358C 00000000 */  nop       
