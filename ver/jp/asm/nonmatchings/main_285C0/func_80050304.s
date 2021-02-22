.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050304
/* 2B704 80050304 00041203 */  sra       $v0, $a0, 8
/* 2B708 80050308 3042001F */  andi      $v0, $v0, 0x1f
/* 2B70C 8005030C 308400E0 */  andi      $a0, $a0, 0xe0
/* 2B710 80050310 00441021 */  addu      $v0, $v0, $a0
/* 2B714 80050314 30C600FF */  andi      $a2, $a2, 0xff
/* 2B718 80050318 00C20018 */  mult      $a2, $v0
/* 2B71C 8005031C 30A500FF */  andi      $a1, $a1, 0xff
/* 2B720 80050320 00001812 */  mflo      $v1
/* 2B724 80050324 34028000 */  ori       $v0, $zero, 0x8000
/* 2B728 80050328 00431023 */  subu      $v0, $v0, $v1
/* 2B72C 8005032C 00A20018 */  mult      $a1, $v0
/* 2B730 80050330 00001812 */  mflo      $v1
/* 2B734 80050334 03E00008 */  jr        $ra
/* 2B738 80050338 306200FF */   andi     $v0, $v1, 0xff
