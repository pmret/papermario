.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011C2EC
/* B29EC 8011C2EC 3C028015 */  lui       $v0, %hi(D_80152210)
/* B29F0 8011C2F0 8C422210 */  lw        $v0, %lo(D_80152210)($v0)
/* B29F4 8011C2F4 00042080 */  sll       $a0, $a0, 2
/* B29F8 8011C2F8 00822021 */  addu      $a0, $a0, $v0
/* B29FC 8011C2FC 8C840000 */  lw        $a0, ($a0)
/* B2A00 8011C300 8C830018 */  lw        $v1, 0x18($a0)
/* B2A04 8011C304 00031080 */  sll       $v0, $v1, 2
/* B2A08 8011C308 00821021 */  addu      $v0, $a0, $v0
/* B2A0C 8011C30C 8C420008 */  lw        $v0, 8($v0)
/* B2A10 8011C310 24630001 */  addiu     $v1, $v1, 1
/* B2A14 8011C314 AC830018 */  sw        $v1, 0x18($a0)
/* B2A18 8011C318 28630002 */  slti      $v1, $v1, 2
/* B2A1C 8011C31C 50600001 */  beql      $v1, $zero, .L8011C324
/* B2A20 8011C320 AC800018 */   sw       $zero, 0x18($a0)
.L8011C324:
/* B2A24 8011C324 03E00008 */  jr        $ra
/* B2A28 8011C328 00000000 */   nop
