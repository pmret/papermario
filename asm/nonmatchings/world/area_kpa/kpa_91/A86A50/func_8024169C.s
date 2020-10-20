.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024169C
/* A880EC 8024169C 3C028011 */  lui       $v0, 0x8011
/* A880F0 802416A0 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* A880F4 802416A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A880F8 802416A8 10400003 */  beqz      $v0, .L802416B8
/* A880FC 802416AC AFBF0010 */   sw       $ra, 0x10($sp)
/* A88100 802416B0 0C03AE06 */  jal       partner_suspend_ability_script
/* A88104 802416B4 00000000 */   nop      
.L802416B8:
/* A88108 802416B8 24020002 */  addiu     $v0, $zero, 2
/* A8810C 802416BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A88110 802416C0 03E00008 */  jr        $ra
/* A88114 802416C4 27BD0018 */   addiu    $sp, $sp, 0x18
