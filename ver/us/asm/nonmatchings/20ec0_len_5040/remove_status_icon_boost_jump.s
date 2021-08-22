.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_status_icon_boost_jump
/* 230A4 80047CA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 230A8 80047CA8 00041040 */  sll       $v0, $a0, 1
/* 230AC 80047CAC 00441021 */  addu      $v0, $v0, $a0
/* 230B0 80047CB0 00021080 */  sll       $v0, $v0, 2
/* 230B4 80047CB4 00441023 */  subu      $v0, $v0, $a0
/* 230B8 80047CB8 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 230BC 80047CBC 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 230C0 80047CC0 00021100 */  sll       $v0, $v0, 4
/* 230C4 80047CC4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 230C8 80047CC8 00621821 */  addu      $v1, $v1, $v0
/* 230CC 80047CCC 80620078 */  lb        $v0, 0x78($v1)
/* 230D0 80047CD0 10400008 */  beqz      $v0, .L80047CF4
/* 230D4 80047CD4 24020001 */   addiu    $v0, $zero, 1
/* 230D8 80047CD8 8C64007C */  lw        $a0, 0x7c($v1)
/* 230DC 80047CDC 3C058010 */  lui       $a1, %hi(D_8010717C)
/* 230E0 80047CE0 24A5717C */  addiu     $a1, $a1, %lo(D_8010717C)
/* 230E4 80047CE4 A0600078 */  sb        $zero, 0x78($v1)
/* 230E8 80047CE8 A0620079 */  sb        $v0, 0x79($v1)
/* 230EC 80047CEC 0C0511FF */  jal       set_hud_element_anim
/* 230F0 80047CF0 AC640080 */   sw       $a0, 0x80($v1)
.L80047CF4:
/* 230F4 80047CF4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 230F8 80047CF8 03E00008 */  jr        $ra
/* 230FC 80047CFC 27BD0018 */   addiu    $sp, $sp, 0x18
