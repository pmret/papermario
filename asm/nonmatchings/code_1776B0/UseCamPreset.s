.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UseCamPreset
/* 17CEFC 8024E61C 3C028028 */  lui       $v0, 0x8028
/* 17CF00 8024E620 80420CE0 */  lb        $v0, 0xce0($v0)
/* 17CF04 8024E624 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17CF08 8024E628 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17CF0C 8024E62C 8C85000C */  lw        $a1, 0xc($a0)
/* 17CF10 8024E630 14400009 */  bnez      $v0, .L8024E658
/* 17CF14 8024E634 24020002 */   addiu    $v0, $zero, 2
/* 17CF18 8024E638 8CA50000 */  lw        $a1, ($a1)
/* 17CF1C 8024E63C 0C0B1EAF */  jal       get_variable
/* 17CF20 8024E640 00000000 */   nop      
/* 17CF24 8024E644 3C01802A */  lui       $at, 0x802a
/* 17CF28 8024E648 A020F2A4 */  sb        $zero, -0xd5c($at)
/* 17CF2C 8024E64C 0C0933CD */  jal       use_cam_preset
/* 17CF30 8024E650 0040202D */   daddu    $a0, $v0, $zero
/* 17CF34 8024E654 24020002 */  addiu     $v0, $zero, 2
.L8024E658:
/* 17CF38 8024E658 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17CF3C 8024E65C 03E00008 */  jr        $ra
/* 17CF40 8024E660 27BD0018 */   addiu    $sp, $sp, 0x18
