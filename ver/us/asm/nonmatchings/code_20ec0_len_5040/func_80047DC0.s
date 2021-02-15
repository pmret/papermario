.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047DC0
/* 231C0 80047DC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 231C4 80047DC4 00041040 */  sll       $v0, $a0, 1
/* 231C8 80047DC8 00441021 */  addu      $v0, $v0, $a0
/* 231CC 80047DCC 00021080 */  sll       $v0, $v0, 2
/* 231D0 80047DD0 00441023 */  subu      $v0, $v0, $a0
/* 231D4 80047DD4 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 231D8 80047DD8 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 231DC 80047DDC 00021100 */  sll       $v0, $v0, 4
/* 231E0 80047DE0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 231E4 80047DE4 00621821 */  addu      $v1, $v1, $v0
/* 231E8 80047DE8 80620084 */  lb        $v0, 0x84($v1)
/* 231EC 80047DEC 10400008 */  beqz      $v0, .L80047E10
/* 231F0 80047DF0 00000000 */   nop
/* 231F4 80047DF4 8C640088 */  lw        $a0, 0x88($v1)
/* 231F8 80047DF8 3C058010 */  lui       $a1, %hi(D_80107474)
/* 231FC 80047DFC 24A57474 */  addiu     $a1, $a1, %lo(D_80107474)
/* 23200 80047E00 A0600084 */  sb        $zero, 0x84($v1)
/* 23204 80047E04 A0600085 */  sb        $zero, 0x85($v1)
/* 23208 80047E08 0C0511FF */  jal       set_menu_icon_script
/* 2320C 80047E0C AC64008C */   sw       $a0, 0x8c($v1)
.L80047E10:
/* 23210 80047E10 8FBF0010 */  lw        $ra, 0x10($sp)
/* 23214 80047E14 03E00008 */  jr        $ra
/* 23218 80047E18 27BD0018 */   addiu    $sp, $sp, 0x18
