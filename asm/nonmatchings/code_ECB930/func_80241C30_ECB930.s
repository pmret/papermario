.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C30_ECB930
/* ECB930 80241C30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* ECB934 80241C34 F7B40018 */  sdc1      $f20, 0x18($sp)
/* ECB938 80241C38 4485A000 */  mtc1      $a1, $f20
/* ECB93C 80241C3C F7B60020 */  sdc1      $f22, 0x20($sp)
/* ECB940 80241C40 4486B000 */  mtc1      $a2, $f22
/* ECB944 80241C44 AFB00010 */  sw        $s0, 0x10($sp)
/* ECB948 80241C48 F7B80028 */  sdc1      $f24, 0x28($sp)
/* ECB94C 80241C4C 4487C000 */  mtc1      $a3, $f24
/* ECB950 80241C50 AFBF0014 */  sw        $ra, 0x14($sp)
/* ECB954 80241C54 0C01B198 */  jal       osGetCause
/* ECB958 80241C58 0080802D */   daddu    $s0, $a0, $zero
/* ECB95C 80241C5C 4616A582 */  mul.s     $f22, $f20, $f22
/* ECB960 80241C60 00000000 */  nop       
/* ECB964 80241C64 4618A502 */  mul.s     $f20, $f20, $f24
/* ECB968 80241C68 00000000 */  nop       
/* ECB96C 80241C6C 3C013F80 */  lui       $at, 0x3f80
/* ECB970 80241C70 44810000 */  mtc1      $at, $f0
/* ECB974 80241C74 00000000 */  nop       
/* ECB978 80241C78 E6000014 */  swc1      $f0, 0x14($s0)
/* ECB97C 80241C7C E6160010 */  swc1      $f22, 0x10($s0)
/* ECB980 80241C80 E6140018 */  swc1      $f20, 0x18($s0)
/* ECB984 80241C84 8FBF0014 */  lw        $ra, 0x14($sp)
/* ECB988 80241C88 8FB00010 */  lw        $s0, 0x10($sp)
/* ECB98C 80241C8C D7B80028 */  ldc1      $f24, 0x28($sp)
/* ECB990 80241C90 D7B60020 */  ldc1      $f22, 0x20($sp)
/* ECB994 80241C94 D7B40018 */  ldc1      $f20, 0x18($sp)
/* ECB998 80241C98 03E00008 */  jr        $ra
/* ECB99C 80241C9C 27BD0030 */   addiu    $sp, $sp, 0x30
