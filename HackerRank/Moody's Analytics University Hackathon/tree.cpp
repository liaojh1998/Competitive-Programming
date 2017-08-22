 else {
	          return _promise2.default.resolve(value).then(function (value) {
	            return step("next", value);
	          }, function (err) {
	            return step("throw", err);
	          });
	        }
	      }
	
	      return step("next");
	    });
	  };
	};

/***/ },
/* 370 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _typeof2 = __webpack_require__(371);
	
	var _typeof3 = _interopRequireDefault(_typeof2);
	
	exports.track = track;
	exports.trackError = trackError;
	exports.trackClick = trackClick;
	exports.trackHover = trackHover;
	exports.identify = identify;
	exports.page = page;
	exports.setPriceCheckId = setPriceCheckId;
	
	var _constants = __webpack_require__(372);
	
	var _constants2 = _interopRequireDefault(_constants);
	
	var _uaParserJ