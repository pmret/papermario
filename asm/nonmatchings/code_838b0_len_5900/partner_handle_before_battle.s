.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_handle_before_battle
/* 84B08 800EB658 3C028011 */  lui       $v0, 0x8011
/* 84B0C 800EB65C 8C42CFD8 */  lw        $v0, -0x3028($v0)
/* 84B10 800EB660 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 84B14 800EB664 AFBF0014 */  sw        $ra, 0x14($sp)
/* 84B18 800EB668 10400012 */  beqz      $v0, .L800EB6B4
/* 84B1C 800EB66C AFB00010 */   sw       $s0, 0x10($sp)
/* 84B20 800EB670 3C108011 */  lui       $s0, 0x8011
/* 84B24 800EB674 2610CFDC */  addiu     $s0, $s0, -0x3024
/* 84B28 800EB678 0C0B1059 */  jal       does_script_exist
/* 84B2C 800EB67C 8E040000 */   lw       $a0, ($s0)
/* 84B30 800EB680 10400003 */  beqz      $v0, .L800EB690
/* 84B34 800EB684 00000000 */   nop      
/* 84B38 800EB688 0C0B102B */  jal       kill_script_by_ID
/* 84B3C 800EB68C 8E040000 */   lw       $a0, ($s0)
.L800EB690:
/* 84B40 800EB690 3C028011 */  lui       $v0, 0x8011
/* 84B44 800EB694 8C42CFEC */  lw        $v0, -0x3014($v0)
/* 84B48 800EB698 8C420034 */  lw        $v0, 0x34($v0)
/* 84B4C 800EB69C 10400005 */  beqz      $v0, .L800EB6B4
/* 84B50 800EB6A0 00000000 */   nop      
/* 84B54 800EB6A4 3C048011 */  lui       $a0, 0x8011
/* 84B58 800EB6A8 8C84C930 */  lw        $a0, -0x36d0($a0)
/* 84B5C 800EB6AC 0040F809 */  jalr      $v0
/* 84B60 800EB6B0 00000000 */   nop      
.L800EB6B4:
/* 84B64 800EB6B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 84B68 800EB6B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 84B6C 800EB6BC 03E00008 */  jr        $ra
/* 84B70 800EB6C0 27BD0018 */   addiu    $sp, $sp, 0x18
